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

#define READ_STRING_LEN 256
#define WRITE_STRING "hellow world!\n"
#define FILE_ROUTE "./RW_EXAMPLE"\

int open_files();

#endif