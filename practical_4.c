#include <stdio.h>

struct personnal
{
    char name[10];
    char dob[20];
    int age;
    
};

int main()
{
    struct personnal p1,p2,p3,p4;

    printf("\nEnter names, date of birth and age of 4 persons\n");

    scanf("%9s %19s %d",p1.name,p1.dob,&p1.age);
    scanf("%9s %19s %d",p2.name,p2.dob,&p2.age);
    scanf("%9s %19s %d",p3.name,p3.dob,&p3.age);
    scanf("%9s %19s %d",p4.name,p4.dob,&p4.age);

    printf("\nAnd this is what you entered \n");

    printf("\n NAME: %s, DOB: %s, AGE: %d",p1.name,p1.dob,p1.age);
    printf("\n  NAME: %s, DOB: %s, AGE: %d",p2.name,p2.dob,p2.age);
    printf("\n  NAME: %s, DOB: %s, AGE: %d",p3.name,p3.dob,p3.age);
    printf("\n  NAME: %s, DOB: %s, AGE: %d",p4.name,p4.dob,p4.age);

    return 0;

}