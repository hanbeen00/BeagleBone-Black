//gpio.c
#include "gpio.h"

int open_files()
{
    int file_descripter = 0;
    int ret = 0;
    char *string_to_write = WRITE_STRING;
    char string_to_read[READ_STRING_LEN] = {0, };

    file_descripter = open(FILE_ROUTE, O_RDWR | O_CREAT, 0666); //파일 열기, 읽기쓰기 + 파일 없으면 만들어라[꼭 뒤에 mode 붙여줘야함] 권한은 읽기/쓰기 모든 유저 가능
    if(file_descripter < 0)
    {
        perror("fail to open"); //errno에 따라 버그 메세지를 출력해주는 함수수
        return -1;
    }

    ret = write(file_descripter, string_to_write, strlen(string_to_write)); //쓰기
    if(ret < 0)
    {
        perror("fail to write");
        close(file_descripter);
        return ret;
    }

    printf("write val : %s write len : %d\n", string_to_write, ret);


    ret = lseek(file_descripter, 0, SEEK_SET); //오프셋 0으로 조정
    if(ret < 0)
    {
        perror("fail to set file offset");
        return ret;
    }

    ret = read(file_descripter, string_to_read, sizeof(string_to_read)); //읽기
    if(ret < 0)
    {
        perror("fail to read");
        close(file_descripter);
        return ret;
    }

    printf("read val : %s read len : %d\n", string_to_read, ret);

    close(file_descripter);
}