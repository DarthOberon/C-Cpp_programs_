#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr;

    ptr = &num;

    printf("Value of the variable: %d\n",num);
    printf("Address of num : %p\n",&num);
    printf("Address of num using pointer: %p\n",ptr);
    getchar();

    return 0;

}