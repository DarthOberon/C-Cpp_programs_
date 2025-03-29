# include <stdio.h>
struct students
{
    char name[15];
    char branch[20];
    float total_percentage;
};

int main()
{
    int i;
    struct students s1[10];

    for ( i = 0; i <10; i++)
    {
        printf("enter the details of student:%d\n",i+1);

        

        printf("name:\n");
        scanf("%s",s1[i].name);

        printf("branch:\n");
        scanf("%s",s1[i].branch);

        printf("total percentage:\n");
        scanf("%f",&s1[i].total_percentage);

    }
    
    for ( i = 0; i <10; i++)
    {
        printf("\nThe details of student:%d\n",i+1);

        printf("name:%s\n",s1[i].name);
        printf("branch:%s\n",s1[i].branch);
        printf("total percentage:%.2f\n",s1[i].total_percentage);

    }
    return 0;
}
