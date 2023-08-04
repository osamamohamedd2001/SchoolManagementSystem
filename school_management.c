#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school_management.h"

// Student structure
struct Student
 {
    int ID;
    char name[100];
    char date_of_birth[12];
    char address[100];
    char phone_number[15];
    int computer_science_score;
};

// Node structure for the linked list
struct Node 
{
    struct Student data;
    struct Node* next;
};

// Queue to hold students using linked list
struct Queue 
{
    struct Node* front;
    struct Node* rear;
};

// Global variable for the student queue for making it accessible to all the functions defined in that file.
struct Queue student_queue;

// Function to initialize the student queue
void initStudentQueue() 
{
    student_queue.front = NULL;
    student_queue.rear = NULL;
}

// Function to add a new student to the queue
void NEW_STUDENT() 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &newNode->data.ID);

    printf("Enter Student Name: ");
    getchar(); // consume the newline character left in the input buffer
    fgets(newNode->data.name, sizeof(newNode->data.name), stdin);
    newNode->data.name[strcspn(newNode->data.name, "\n")] = '\0'; // remove the newline character

    printf("Enter Date of Birth (dd/mm/yyyy): ");
    scanf("%s", newNode->data.date_of_birth);

    printf("Enter Address: ");
    getchar();
    fgets(newNode->data.address, sizeof(newNode->data.address), stdin);
    newNode->data.address[strcspn(newNode->data.address, "\n")] = '\0';

    printf("Enter Phone Number: ");
    scanf("%s", newNode->data.phone_number);

    printf("Enter Computer Science Score: ");
    scanf("%d", &newNode->data.computer_science_score);

    newNode->next = NULL;

    if (student_queue.rear == NULL) {
        student_queue.front = newNode;
        student_queue.rear = newNode;
    } else {
        student_queue.rear->next = newNode;
        student_queue.rear = newNode;
    }

    printf("Student added successfully.\n");
}

// Function to delete a student from the queue
void DELETE_STUDENT() {
    int studentID;
    struct Node* current = student_queue.front;
    struct Node* previous = NULL;

    printf("Enter Student ID to Delete: ");
    scanf("%d", &studentID);

    while (current != NULL) {
        if (current->data.ID == studentID) {
            if (current == student_queue.front) {
                student_queue.front = current->next;
                free(current);
            } else if (current == student_queue.rear) {
                student_queue.rear = previous;
                previous->next = NULL;
                free(current);
            } else {
                previous->next = current->next;
                free(current);
            }
            printf("Student with ID %d deleted successfully.\n", studentID);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Student with ID %d not found.\n", studentID);
}

// Function to list all students in the queue
void STUDENT_LIST() {
    struct Node* current = student_queue.front;

    if (current == NULL) {
        printf("No students found.\n");
        return;
    }

    printf("ID\tName\t\tDate of Birth\t\tAddress\t\t\tPhone\t\tScore\n");
    printf("------------------------------------------------------------------------------------------------------\n");

    while (current != NULL) {
        printf("%d\t%-20s%-20s%-30s%-15s%d\n",
               current->data.ID,
               current->data.name,
               current->data.date_of_birth,
               current->data.address,
               current->data.phone_number,
               current->data.computer_science_score);

        current = current->next;
    }
}

// Function to edit student details in the queue
void STUDENT_EDIT() {
    int studentID;
    struct Node* current = student_queue.front;

    printf("Enter Student ID to Edit: ");
    scanf("%d", &studentID);

    while (current != NULL) {
        if (current->data.ID == studentID) {
            printf("Enter Student Name: ");
            getchar();
            fgets(current->data.name, sizeof(current->data.name), stdin);
            current->data.name[strcspn(current->data.name, "\n")] = '\0'; // remove the newline character

            printf("Enter Date of Birth (dd/mm/yyyy): ");
            scanf("%s", current->data.date_of_birth);

            printf("Enter Address: ");
            getchar();
            fgets(current->data.address, sizeof(current->data.address), stdin);
            current->data.address[strcspn(current->data.address, "\n")] = '\0';

            printf("Enter Phone Number: ");
            scanf("%s", current->data.phone_number);

            printf("Enter Computer Science Score: ");
            scanf("%d", &current->data.computer_science_score);

            printf("Student details updated successfully.\n");
            return;
        }

        current = current->next;
    }

    printf("Student with ID %d not found.\n", studentID);
}

// Function to rank students based on their scores
void RANK_STUDENT() {
    struct Node* current = student_queue.front;
    int studentCount = 0;

    // Count the number of students in the queue
    while (current != NULL) {
        studentCount++;
        current = current->next;
    }

    // Create an array of pointers to store student nodes
    struct Node* studentArray[studentCount];
    current = student_queue.front;

    // Fill the array with student nodes
    for (int i = 0; i < studentCount; i++) {
        studentArray[i] = current;
        current = current->next;
    }

    // Perform a simple bubble sort to rank students based on scores
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (studentArray[j]->data.computer_science_score < studentArray[j + 1]->data.computer_science_score) {
                struct Node* temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }

    // Print the ranked students
    printf("Rank\tID\tName\t\tScore\n");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%d\t%-20s%d\n", i + 1, studentArray[i]->data.ID, studentArray[i]->data.name, studentArray[i]->data.computer_science_score);
    }
}

// Function to input student score by student ID
void STUDENT_SCORE(int studentID) {
    struct Node* current = student_queue.front;

    while (current != NULL) {
        if (current->data.ID == studentID) {
            printf("Enter Computer Science Score for Student ID %d: ", studentID);
            scanf("%d", &current->data.computer_science_score);
            printf("Computer Science Score for Student ID %d updated successfully.\n", studentID);
            return;
        }

        current = current->next;
    }

    printf("Student with ID %d not found.\n", studentID);
}

// Function to search for a student by student ID
void SEARCH_STUDENT(int studentID) {
    struct Node* current = student_queue.front;

    while (current != NULL) {
        if (current->data.ID == studentID) {
            printf("ID\tName\t\tDate of Birth\t\tAddress\t\t\tPhone\t\tScore\n");
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("%d\t%-20s%-20s%-30s%-15s%d\n",
                   current->data.ID,
                   current->data.name,
                   current->data.date_of_birth,
                   current->data.address,
                   current->data.phone_number,
                   current->data.computer_science_score);
            return;
        }

        current = current->next;
    }

    printf("Student with ID %d not found.\n", studentID);
}

// Function to calculate the average score of all students
float AVERAGE_SCORE() 
{
    struct Node* current = student_queue.front;
    int totalStudents = 0;
    int totalScore = 0;

    while (current != NULL) 
	{
        totalStudents++;
        totalScore += current->data.computer_science_score;
        current = current->next;
    }

    if (totalStudents == 0) 
	{
        printf("No students found.\n");
        return 0;
    }

    return (float)totalScore / totalStudents;
}

// Function to sort students by their names
void SORT_STUDENTS_BY_NAME() {
    struct Node* current = student_queue.front;
    int studentCount = 0;

    // Count the number of students in the queue
    while (current != NULL) {
        studentCount++;
        current = current->next;
    }

    // Create an array of pointers to store student nodes
    struct Node* studentArray[studentCount];
    current = student_queue.front;

    // Fill the array with student nodes
    for (int i = 0; i < studentCount; i++) {
        studentArray[i] = current;
        current = current->next;
    }

    // Perform a simple bubble sort to sort students by names
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(studentArray[j]->data.name, studentArray[j + 1]->data.name) > 0) {
                struct Node* temp = studentArray[j];
                studentArray[j] = studentArray[j + 1];
                studentArray[j + 1] = temp;
            }
        }
    }

    // Print the sorted students
    printf("ID\tName\t\tDate of Birth\t\tAddress\t\t\tPhone\t\tScore\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-20s%-20s%-30s%-15s%d\n",
               studentArray[i]->data.ID,
               studentArray[i]->data.name,
               studentArray[i]->data.date_of_birth,
               studentArray[i]->data.address,
               studentArray[i]->data.phone_number,
               studentArray[i]->data.computer_science_score);
    }
}
