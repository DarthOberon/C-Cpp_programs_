#include <stdio.h>

int main()
{
    int num1;
    int num2;
    int sum;
    
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    
    printf("enter any 2 no:");
    scanf("%d%d",ptr1,ptr2);

    sum = *ptr1 + *ptr2;
    
    printf("Sum using pointers :%d\n",sum);
    return 0;
    
}
