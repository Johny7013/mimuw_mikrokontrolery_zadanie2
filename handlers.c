#include "handlers.h"

// MODE button handler
void EXTI0_IRQHandler() {
    EXTI->PR = EXTI_PR_PR0;

    handleButtonChange(MODE, MODE_BTN_STATE);
//    putMessageToTransmit(buttonsStateChanges[MODE][0]);

    if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
        transmit();
    }
}

// LEFT button handler
void EXTI3_IRQHandler() {
    EXTI->PR = EXTI_PR_PR3;

    handleButtonChange(LEFT, LEFT_BTN_STATE);
//    putMessageToTransmit(buttonsStateChanges[LEFT][0]);

    if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
        transmit();
    }
}

// RIGHT button handler
void EXTI4_IRQHandler() {
    EXTI->PR = EXTI_PR_PR4;

    handleButtonChange(RIGHT, RIGHT_BTN_STATE);
//    putMessageToTransmit(buttonsStateChanges[RIGHT][0]);

    if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
        transmit();
    }
}

// UP & DOWN button handler
void EXTI9_5_IRQHandler() {
    uint32_t isr = EXTI->PR;

    if (isr & EXTI_PR_PR5) {
        //UP
        EXTI->PR = EXTI_PR_PR5;

        handleButtonChange(UP, UP_BTN_STATE);
//        putMessageToTransmit(buttonsStateChanges[UP][0]);

        if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
            transmit();
        }
    } else if (isr & EXTI_PR_PR6) {
        //DOWN
        EXTI->PR = EXTI_PR_PR6;

        handleButtonChange(DOWN, DOWN_BTN_STATE);
//        putMessageToTransmit(buttonsStateChanges[DOWN][0]);

        if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
            transmit();
        }
    }
}

// FIRE & USER button handler
void EXTI15_10_IRQHandler() {

    uint32_t isr = EXTI->PR;

    if (isr & EXTI_PR_PR10) {
        //FIRE
        EXTI->PR = EXTI_PR_PR10;

        handleButtonChange(FIRE, FIRE_BTN_STATE);
//        putMessageToTransmit(buttonsStateChanges[FIRE][0]);

        if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
            transmit();
        }
    } else if (isr & EXTI_PR_PR13) {
        //USER
        EXTI->PR = EXTI_PR_PR13;

        handleButtonChange(USER, USER_BTN_STATE);
//        putMessageToTransmit(buttonsStateChanges[USER][0]);

        if ((DMA1_Stream6->CR & DMA_SxCR_EN) == 0 && (DMA1->HISR & DMA_HISR_TCIF6) == 0) {
            transmit();
        }
    }

}

void DMA1_Stream6_IRQHandler() {
    /* Read interrupt from DMA1 */
    uint32_t isr = DMA1->HISR;
    if (isr & DMA_HISR_TCIF6) {
        /* Handle end of transfer on stream 6 */
        DMA1->HIFCR = DMA_HIFCR_CTCIF6;

        transmit();
    }
}