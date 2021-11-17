#ifndef TASK2_BUTTONS_H
#define TASK2_BUTTONS_H

#include <gpio.h>
#include <stm32.h>

#define USER_BTN_GPIO GPIOC
#define USER_BTN_PIN 13

#define LEFT_BTN_GPIO GPIOB
#define LEFT_BTN_PIN 3
#define RIGHT_BTN_GPIO GPIOB
#define RIGHT_BTN_PIN 4
#define UP_BTN_GPIO GPIOB
#define UP_BTN_PIN 5
#define DOWN_BTN_GPIO GPIOB
#define DOWN_BTN_PIN 6
#define FIRE_BTN_GPIO GPIOB
#define FIRE_BTN_PIN 10

#define MODE_BTN_GPIO GPIOA
#define MODE_BTN_PIN 0

#define USER_BTN_STATE ((USER_BTN_GPIO->IDR >> USER_BTN_PIN) & 1)
#define LEFT_BTN_STATE ((LEFT_BTN_GPIO->IDR >> LEFT_BTN_PIN) & 1)
#define RIGHT_BTN_STATE ((RIGHT_BTN_GPIO->IDR >> RIGHT_BTN_PIN) & 1)
#define UP_BTN_STATE ((UP_BTN_GPIO->IDR >> UP_BTN_PIN) & 1)
#define DOWN_BTN_STATE ((DOWN_BTN_GPIO->IDR >> DOWN_BTN_PIN) & 1)
#define FIRE_BTN_STATE ((FIRE_BTN_GPIO->IDR >> FIRE_BTN_PIN) & 1)
#define MODE_BTN_STATE ((MODE_BTN_GPIO->IDR >> MODE_BTN_PIN) & 1)

#define BUTTONS_NUM 7
#define BUTTONS_INITIALIZATION {{1, 1, 1, 1, 1, 1, 0}}

enum buttonNumber {
    USER = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4,
    FIRE = 5,
    MODE = 6
};

extern const char* buttonsStateChanges[BUTTONS_NUM][2];

struct buttons {
    unsigned int state[BUTTONS_NUM];
};

void ButtonsConfigure();

void ButtonsEnableInterrupts();

#endif //TASK2_BUTTONS_H
