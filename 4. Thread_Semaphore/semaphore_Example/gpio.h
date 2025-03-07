//gpio.h
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

#define MAX_THREAD_NUM 2

void start_gpio_thread();

#endif