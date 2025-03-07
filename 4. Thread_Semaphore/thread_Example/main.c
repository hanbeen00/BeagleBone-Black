//main.c
#include "gpio.h"

int main()
{
    start_gpio_thread();
    while(1); //부모 프로세스가 끝나면, 자식 스레드가 종료됨에 주의
}
