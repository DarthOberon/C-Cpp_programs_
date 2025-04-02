#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "student.txt"

typedef struct {
    int roll_no;
    char name[50];
    float marks;
} student;

student students[MAX_STUDENTS];
int student_count = 0;

void loadstudent();
void savestudent();
void addstudent();
void deletestudent();
void updatestudent();
void viewstudent();
void menu();

int main() {
    loadstudent();
    menu();
    return 0;
}

// Function to load student data from file
void loadstudent() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No existing records found.\n");
        return;
    }
    
    student_count = 0;
    while (fscanf(file, "%d %s %f", &students[student_count].roll_no, students[student_count].name, &students[student_count].marks) == 3) {
        student_count++;
    }
    
    fclose(file);
}

// Function to save student data to file
void savestudent() {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("Error saving file.\n");
        return;
    }
    
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    
    fclose(file);
    printf("Data saved successfully.\n");
}

// Function to add a student
void addstudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    students[student_count++] = s;
    savestudent();
    printf("Student added successfully.\n");
}

// Function to delete a student
void deletestudent() {
    int roll_no, found = 0;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            break;
        }
    }

    if (found) {
        savestudent();
        printf("Student deleted successfully.\n");
    } else {
        printf("Student with roll number %d not found.\n", roll_no);
    }
}

// Function to update a student's record
void updatestudent() {
    int roll_no, found = 0;
    printf("Enter roll number to update: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            break;
        }
    }

    if (found) {
        savestudent();
        printf("Student updated successfully.\n");
    } else {
        printf("Student with roll number %d not found.\n", roll_no);
    }
}

// Function to view all students
void viewstudent() {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n%-10s%-20s%-10s\n", "Roll No", "Name", "Marks");
    printf("------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        printf("%-10d%-20s%-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

// Menu function
void menu() {
    int choice;
    do {
        printf("\n============= STUDENT RECORD MANAGEMENT =====================\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Update student\n");
        printf("4. View students\n");
        printf("5. Save and exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addstudent(); break;
            case 2: deletestudent(); break;
            case 3: updatestudent(); break;
            case 4: viewstudent(); break;
            case 5: savestudent(); printf("Exiting...\n"); return;
            default: printf("Invalid choice, try again.\n");
        }
    } while (1);
}
