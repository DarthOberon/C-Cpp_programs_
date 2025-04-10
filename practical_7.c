# include <stdio.h>
# include <stdlib.h>

int main()
{
    FILE *file,*evenfile, *oddfile;
    int n,i,num,numbers[100];

    printf("Enter how many numbers you want to enter: ");
    scanf("%d",&n);

    file =  fopen("new.txt","w");
    if (file == NULL)
    {
        printf("Error: Couldn't open the file 'new.txt'\n");
        return 1;
    }

    printf("Enter %d integers:\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&num);
        fprintf(file,"%d ",num);
    }

    fclose(file);
    
    file = fopen("new.txt","r");
    evenfile = fopen("even.txt","w");
    oddfile = fopen("odd.txt","w");

    if (file == NULL || evenfile == NULL || oddfile == NULL)
    {
        printf("Error: Could not open one or more file\n");
        return 1;
    }
    
    for(i = 0; i<n;i++)
    {
        fscanf(file,"%d",&num);
        if(num %2 == 0)
        {
            fprintf(evenfile,"%d ",num);
        }
        else
        {
            fprintf(oddfile,"%d ",num);
        }
    }

    fclose(file);
    fclose(evenfile);
    fclose(oddfile);

    oddfile = fopen("odd.txt", "r");
    printf("\nOdd numbers:\n");
    while (fscanf(oddfile, "%d", &num) != EOF)
         printf("%d ", num);
     fclose(oddfile);
    
        
    evenfile = fopen("even.txt", "r");
    printf("\nEven numbers:\n");
    while (fscanf(evenfile, "%d", &num) != EOF)
        printf("%d ", num);
    fclose(evenfile);
    
    return 0;
        

}