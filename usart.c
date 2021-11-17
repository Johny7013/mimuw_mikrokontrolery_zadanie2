#include "usart.h"

void USARTConfigure() {
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configuration of TXD on PA2 and RXD on PA3
    GPIOafConfigure(GPIOA,
                    2,
                    GPIO_OType_PP,
                    GPIO_Fast_Speed,
                    GPIO_PuPd_NOPULL,
                    GPIO_AF_USART2);
    GPIOafConfigure(GPIOA,
                    3,
                    GPIO_OType_PP,
                    GPIO_Fast_Speed,
                    GPIO_PuPd_UP,
                    GPIO_AF_USART2);

    // set USART parameters
    USART2->CR1 = USART_CR1_RE | USART_CR1_TE;
    USART2->CR2 = 0;
    USART2->BRR = (PCLK1_HZ + (BAUD / 2U)) / BAUD;

    // set USART to transmit and receive with DMA
    USART2->CR3 = USART_CR3_DMAT | USART_CR3_DMAR;
}

void DMAConfigure() {
    RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;

    // configure DMA receiver
    DMA1_Stream6->CR = 4U << 25 |
                       DMA_SxCR_PL_1 |
                       DMA_SxCR_MINC |
                       DMA_SxCR_DIR_0 |
                       DMA_SxCR_TCIE;

    DMA1_Stream6->PAR = (uint32_t)&USART2->DR;
}

void USARTEnable() {
    // turn on USART
    USART2->CR1 |= USART_CR1_UE;
}

void DMAEnable() {
    // turn on exceptions
    DMA1->HIFCR = DMA_HIFCR_CTCIF6 |
                  DMA_HIFCR_CTCIF5;
    NVIC_EnableIRQ(DMA1_Stream6_IRQn);
    NVIC_EnableIRQ(DMA1_Stream5_IRQn);
}
