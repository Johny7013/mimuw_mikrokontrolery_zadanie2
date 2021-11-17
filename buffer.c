#include "buffer.h"

static char* transmit_buffer[TRANSMIT_BUFFER_SIZE];
static unsigned int transmit_buffer_begin = 0;
static unsigned int transmit_buffer_end = 0;
static bool bufferFull = false;

void putMessageToTransmit(const char* msg) {
    if (!bufferFull) {
        transmit_buffer[transmit_buffer_end] = (char*) msg;
        transmit_buffer_end++;
        transmit_buffer_end %= TRANSMIT_BUFFER_SIZE;

        if (transmit_buffer_end == transmit_buffer_begin) {
            bufferFull = true;
        }
    }
}

void handleButtonChange(enum buttonNumber btnNum, unsigned int btnState) {
    putMessageToTransmit(buttonsStateChanges[btnNum][btnState]);
}

void transmit() {
    if(transmit_buffer_begin != transmit_buffer_end || bufferFull) {
        DMA1_Stream6->M0AR = (uint32_t)transmit_buffer[transmit_buffer_begin];
        DMA1_Stream6->NDTR = strlen(transmit_buffer[transmit_buffer_begin]);
        DMA1_Stream6->CR |= DMA_SxCR_EN;

        transmit_buffer_begin++;
        transmit_buffer_begin %= TRANSMIT_BUFFER_SIZE;
        bufferFull = false;
    }
}