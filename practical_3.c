# include <stdio.h>
int main()
{
    int variable= 100;
    int *ptr1;
    int **ptr2;

    ptr1 = &variable;
    ptr2 = &ptr1;

    printf("value of variable:%d\n",variable);
    printf("value of variable using ptr1:%d\n",*ptr1);
    printf("value of variable using ptr2:%d\n",**ptr2);

    printf("Address of variable:%p\n",&variable);
    printf("Address of variable using ptr1:%p\n",ptr1);
    printf("Address of variable using ptr2:%p\n",ptr2);

    return 0;

}