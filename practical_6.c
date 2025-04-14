# include <stdio.h>
# include <stdlib.h>

int main()
{
    int *ptr;
    int *calloc_ptr;
    int initial_size = 3, final_size = 5;

    ptr = (int *)malloc(initial_size * sizeof(int));
    if (ptr == NULL){
        printf("Memory Allocation Failed!!");
        exit(0);
    }
    for (int i=0;i<initial_size;i++)
    {
        ptr[i] = (i+1) * 10;
    }

    ptr = (int*)realloc(ptr, 5 * sizeof(int));
    if (ptr == NULL){
        printf("Memory Reallocation Failed!!");
        exit(0);
    }

    for (int i = initial_size; i<final_size; i++)
    {
        ptr[i] = (i+1)* 10;
    }

    printf("All values after reallocating:\n");
    for (int i = 0; i < final_size; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    
    calloc_ptr = (int *)calloc(5,sizeof(int));
    if (calloc_ptr == NULL){
        printf("Calloc Allocation Failed!!");
        exit(0);
    }
    printf("Values stored using calloc (should be all zeros):\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", calloc_ptr[i]);
    printf("\n");

    free(ptr);
    free(calloc_ptr);

    return 0;
}