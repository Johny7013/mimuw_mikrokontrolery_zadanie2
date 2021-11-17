#ifndef TASK2_HANDLERS_H
#define TASK2_HANDLERS_H

#include <gpio.h>
#include <stm32.h>
#include "buffer.h"

// MODE button handler
void EXTI0_IRQHandler();

// LEFT button handler
void EXTI3_IRQHandler();

// RIGHT button handler
void EXTI4_IRQHandler();

// UP & DOWN button handler
void EXTI9_5_IRQHandler();

// FIRE & USER button handler
void EXTI15_10_IRQHandler();

void DMA1_Stream6_IRQHandler();


#endif //TASK2_HANDLERS_H
