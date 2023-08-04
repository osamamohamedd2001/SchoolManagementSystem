#ifndef SCHOOL_MANAGEMENT_H
#define SCHOOL_MANAGEMENT_H


// Function to initialize the student queue
void initStudentQueue();

// Function to add a new student to the queue
void NEW_STUDENT();

// Function to delete a student from the queue
void DELETE_STUDENT();

// Function to list all students in the queue
void STUDENT_LIST();

// Function to edit student details in the queue
void STUDENT_EDIT();

// Function to rank students based on their scores
void RANK_STUDENT();

// Function to input student score by student ID
void STUDENT_SCORE(int studentID);

// Function to search for a student by student ID
void SEARCH_STUDENT(int studentID);

// Function to calculate the average score of all students
float AVERAGE_SCORE();

// Function to sort students by their names
void SORT_STUDENTS_BY_NAME();

#endif
