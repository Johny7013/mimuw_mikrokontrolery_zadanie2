#ifndef TASK2_BUFFER_H
#define TASK2_BUFFER_H

#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "buttons.h"

#define TRANSMIT_BUFFER_SIZE 64

void putMessageToTransmit(const char* msg);

void handleButtonChange(enum buttonNumber btnNum, unsigned int btnState);

void transmit();

#endif //TASK2_BUFFER_H
