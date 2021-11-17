#include "buttons.h"
#include "usart.h"
#include "handlers.h"

int main() {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_DMA1EN;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

    USARTConfigure();
    DMAConfigure();

    DMAEnable();
    USARTEnable();

    ButtonsConfigure();
    ButtonsEnableInterrupts();
}
