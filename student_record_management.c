# include <stdio.h>
#include <string.h>
# include <stdlib.h>

# define MAX_STUDENTS 100

typedef struct 
{
    int roll_no;
    char name[50];
    float marks;
} student;

student students [MAX_STUDENTS];
int student_count = 0;

void loadstudent();
void savestudent();
void addstudent();
void deletestudent();
void updatestudent();
void viewstudent();
void menu();

int main()
{
    loadstudent();
    menu();
    return 0;
}

void loadstudent()
{
    FILE * file = fopen ("student.txt","r");
    if(!file)
    {
        printf("Error opening file");
        return;
    }
    for (int i = 0; i <student_count; i++)
    {
        fprintf(file,"%d %s %.2f\n",students[i].roll_no,students[i].name,students[i].marks);
    }
    fclose(file);
    printf("Data saved successfully\n");
}

void addstudent()
{
    if (student_count>= MAX_STUDENTS)
    {
        printf("student list is full\n");
        return;
    }
    student s;
    printf("enter roll:");
    scanf("%d",&s.roll_no);
    printf("enter name:");
    scanf("%s",s.name);
    printf("enter roll:");
    scanf("%f",&s.marks);

    students[student_count++] =s;
    savestudent();
    printf("student added successfully");
}

void deletestudent()
{
    int roll_no,found =0;
    printf("enter roll to delete:");
    scanf("%d",&roll_no);

    for (int i = 0; i < student_count; i++)
    {
        if(students[i].roll_no == roll_no)
        {
            found = 1;
            for (int j = 0; j <student_count-1 ; j++)
            {
                students[j] = students[j + 1];
            }
            student_count-- ;
            break;
            
        }
    }
    if(found)
    {
        savestudent(;
        printf("student deleted successfully\n"));
    }
    else
    {
        printf("student with roll %d nit found",roll_no);
    }
}

void updatestudent()
{
    int roll_no, found =0;
    printf("enter roll to delete:");
    scanf("%d",&roll_no);

    for (int i = 0; i < student_count; i++)
    {
        if(students[i].roll_no == roll_no)
        {
            found = 1;
            printf("enter new name:");
            scanf("%s",students[i].name);
            printf("enter new marks:");
            scanf("%f",students[i].marks);
            break;
        }
    }
    if ((found))
    {
        savestudent();
        printf("student updated successfuly");
    }
    else
    {
        printf("student with roll %d nit found",roll_no);
    }
}

void viewstudent()
{
    if(student_count == 0)
    {
        printf("no student avilable");
        return;

    }
    printf("\n%-10s%-20s%-10s\n","rollno","name","marks");
    printf("-----------------------------------------\n");

    for (int i = 0; i < student_count; i++)
    {
        printf("\n%-10d%-20s%-10.2f\n",students[i].roll_no,students[i].name,students[i].marks);
    }
    
}

void menu()
{
    int choice;
    do
    {
        printf("\n=============STUDENT RECORD MANAGEMENT=====================\n");
        printf("1. Add student\n");
        printf("2. delete student\n");
        printf("3. update student\n");
        printf("4. view student\n");
        printf("5. save and exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: addstudent():
            break;
        case 2 :deletestudent():
            break;
        case 3 :updatestudent();
            break;
        case 4 :viewstudent();
            break;
        case 5 : savestudent(); printf("exiting....\n");
            break;
        default:
            printf("invalid choice, try again");
        }
    } 
    while (1);
}

    
