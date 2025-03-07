//gpio.c
#include "gpio.h"

void thread_gpio(void *arg)
{
    int *argument_address = (int *)arg;
    printf("argument address : %p, \n", argument_address);

    while (1)
    {
        printf("hellow world!\n");
        sleep(1);
    }
}

void thread_gpio2(void *arg)
{
    int *argument_address = (int *)arg;
    printf("argument address : %p, \n", argument_address);

    while (1)
    {
        printf("bye world!\n");
        sleep(1);
    }
}

void start_gpio_thread()
{
    pthread_t tid[2] = {0, };
    void (*function_pointer[2]) = {&thread_gpio, &thread_gpio2};
    static int argument = 0; //정적 지역변수로, c의 메모리 영역중 데이터 영역에 저장됨. 즉 함수가 끝나도 메모리 값이 반환되지 않음
    //함수가 끝나면 지역변수는 메모리영역이 유효하지 않게 되니 정적 변수로 선언 해줘야함.
    int ret = 0;
    int i = 0;
    printf("argument address : %p, \n", &argument);

    for (i = 0; i < MAX_THREAD_NUM; i++)
    {
        ret = pthread_create(&tid[i], NULL, (void *)function_pointer[i], &argument);  //스레드 만들고 gpio, gpio2번 순서대로 스레드를 만듦, argument 주소를 넘겨주면 void *arg 에서 받음
        if (ret < 0)
        {
            printf("[%d]", i);
            perror("create thread gpio fail");
            return;
        }

        ret = pthread_detach(tid[i]); //스레드를 활성화함
        if (ret < 0)
        {
            printf("[%d]", i);
            perror("detach thread gpio fail");
            return;
        }
    }
}