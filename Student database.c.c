#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full!\n");
        return;
    }

    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    getchar();  // consume newline

    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';  // remove newline

    printf("Enter student age: ");
    scanf("%d", &newStudent.age);

    students[studentCount++] = newStudent;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("-----------------------------\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("Student Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
