#include "buttons.h"

void ButtonsConfigure() {
    // turn on clocking of devices needed
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;
    // configuration of mode button interrupt
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

    // mode button
    GPIOinConfigure(MODE_BTN_GPIO,
                    MODE_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;

    // user button

    GPIOinConfigure(USER_BTN_GPIO,
                    USER_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

    // joystick buttons

    GPIOinConfigure(FIRE_BTN_GPIO,
                    FIRE_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI10_PB;

    GPIOinConfigure(UP_BTN_GPIO,
                    UP_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI5_PB;

    GPIOinConfigure(DOWN_BTN_GPIO,
                    DOWN_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI6_PB;

    GPIOinConfigure(LEFT_BTN_GPIO,
                    LEFT_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PB;

    GPIOinConfigure(RIGHT_BTN_GPIO,
                    RIGHT_BTN_PIN,
                    GPIO_PuPd_UP,
                    EXTI_Mode_Interrupt,
                    EXTI_Trigger_Rising_Falling);

    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PB;
}

void ButtonsEnableInterrupts() {
    EXTI->IMR |= 0;
    EXTI->PR |= 0;

    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_EnableIRQ(EXTI3_IRQn);
    NVIC_EnableIRQ(EXTI4_IRQn);
    NVIC_EnableIRQ(EXTI9_5_IRQn);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
}

const char* buttonsStateChanges[BUTTONS_NUM][2] = {
        {"USER PRESSED\r\n\0", "USER RELEASED\r\n\0"},
        {"LEFT PRESSED\r\n\0", "LEFT RELEASED\r\n\0"},
        {"RIGHT PRESSED\r\n\0", "RIGHT RELEASED\r\n\0"},
        {"UP PRESSED\r\n\0", "UP RELEASED\r\n\0"},
        {"DOWN PRESSED\r\n\0", "DOWN RELEASED\r\n\0"},
        {"FIRE PRESSED\r\n\0", "FIRE RELEASED\r\n\0"},
        {"MODE RELEASED\r\n\0", "MODE PRESSED\r\n\0"},
};
