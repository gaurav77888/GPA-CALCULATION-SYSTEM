/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COURSE 8
#define MAX_NAME 50

struct course {
    char name[MAX_NAME];
    float marks;
};

void getCourses(struct course courses[]) {

    char subjects[MAX_COURSE][MAX_NAME] = {
        "Advance Calculus",
        "Introduction to Computing",
        "Ordinary Differential Equation",
        "Digital Logic Design",
        "Computer Programming",
        "Data Analysis",
        "Computer Programming Lab",
        "Language Lab"
    };

    char input[100];
    char extra;
    float marks;

    printf("\n========== ENTER SUBJECT MARKS ==========\n");

    for (int i = 0; i < MAX_COURSE; i++) {

        strcpy(courses[i].name, subjects[i]);

        while (1) {
            printf("\nEnter marks for %s (0-100): ",
                   courses[i].name);

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf("Input error. Please try again.\n");
                continue;
            }

            if (sscanf(input, " %f %c", &marks, &extra) == 1
                && marks >= 0 && marks <= 100) {
                courses[i].marks = marks;
                break;
            }

            printf("Invalid input! Enter marks between 0 and 100.\n");
        }
    }
}

void displayCourses(struct course courses[]) {

    printf("\n============== MARKS REPORT ==============\n");
    printf("%-35s %s\n", "SUBJECT", "MARKS");
    printf("------------------------------------------\n");

    for (int i = 0; i < MAX_COURSE; i++) {
        printf("%-35s %.2f\n",
               courses[i].name,
               courses[i].marks);
    }
}

void calculateGPA(struct course courses[]) {

    float total = 0;
    float average;
    float gpa;

    for (int i = 0; i < MAX_COURSE; i++) {
        total += courses[i].marks;
    }

    average = total / MAX_COURSE;
    gpa = average / 10;

    printf("\n============== GPA RESULT ==============\n");
    printf("Total Subjects : %d\n", MAX_COURSE);
    printf("Total Marks    : %.2f / 800\n", total);
    printf("Average Marks  : %.2f\n", average);
    printf("Final GPA      : %.2f / 10\n", gpa);
    printf("========================================\n");
}

int main() {

    struct course courses[MAX_COURSE];
    char studentName[100];
    char rollNumber[30];

    printf("========================================\n");
    printf("       GPA CALCULATION SYSTEM\n");
    printf("========================================\n");

    printf("\nEnter Student Name: ");
    fgets(studentName, sizeof(studentName), stdin);
    studentName[strcspn(studentName, "\n")] = '\0';

    printf("Enter Roll Number: ");
    fgets(rollNumber, sizeof(rollNumber), stdin);
    rollNumber[strcspn(rollNumber, "\n")] = '\0';

    getCourses(courses);

    printf("\n============== STUDENT DETAILS ==============\n");
    printf("Student Name : %s\n", studentName);
    printf("Roll Number  : %s\n", rollNumber);

    displayCourses(courses);
    calculateGPA(courses);

    printf("\nThank you for using GPA Calculation System!\n");

    return 0;
}
