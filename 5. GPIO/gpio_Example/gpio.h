#ifndef __GPIO__
#define __GPIO__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <linux/gpio.h>
#include <sys/ioctl.h>

#define err(fmt, ...) printf("[\x1b[31m%s\x1b[0m]" fmt "\n", __FUNCTION__, ##__VA_ARGS__)
#define debug(fmt, ...) printf("[\x1b[33m%s\x1b[0m]" fmt "\n", __FUNCTION__, ##__VA_ARGS__)

#define GPIO_CHAR_DEVICE_ROUTE "/dev/gpiochip"

#define GPIO_CHIP0_ROUTE GPIO_CHAR_DEVICE_ROUTE "0"
#define GPIO_CHIP1_ROUTE GPIO_CHAR_DEVICE_ROUTE "1"
#define GPIO_CHIP2_ROUTE GPIO_CHAR_DEVICE_ROUTE "2"
#define GPIO_CHIP3_ROUTE GPIO_CHAR_DEVICE_ROUTE "3"
#define GPIO_CHIP4_ROUTE GPIO_CHAR_DEVICE_ROUTE "4"

#define GPIO_CONSUMER_LED "LED_TOGGLE"
#define GPIO_READ_VALUE "READ_VALUE"

typedef enum
{
    GPIO_CHIP0,
    GPIO_CHIP1,
    GPIO_CHIP2,
    GPIO_CHIP3,
    GPIO_CHIP4
}GPIO_CHIP_NUMBER;

#define GPIO_LED_OFFSET 13
#define GPIO_READ_VAL_OFFSET 12

typedef enum
{
    GPIO_NAME_LED_CONTROL,
    GPIO_NAME_READ_VAL,
    GPIO_NAME_MAX_NUMBER
}GPIO_NAME;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH,
}GPIO_VALUES;

void start_gpio_thread();

#endif