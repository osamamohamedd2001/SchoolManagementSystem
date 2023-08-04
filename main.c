#include <stdio.h>
#include "school_management.h"

int main() {
    int choice;
    int studentID;

    // Initialize the student queue
    initStudentQueue();
	
	
    while (1) 
	{
        printf("\n--- School Management System ---\n");
        printf("1. Add New Student\n");
        printf("2. Delete Student\n");
        printf("3. List All Students\n");
        printf("4. Edit Student Details\n");
        printf("5. Rank Students\n");
        printf("6. Input Student Score\n");
        printf("7. Search Student\n");
        printf("8. Average Score of Students\n");
        printf("9. Sort Students by Name\n");
        printf("0. Exit\n");
        printf("Enter your choice from 0 to 9: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            case 1:
                NEW_STUDENT();
                break;

            case 2:
                DELETE_STUDENT();
                break;

            case 3:
                STUDENT_LIST();
                break;

            case 4:
                STUDENT_EDIT();
                break;

            case 5:
                RANK_STUDENT();
                break;

            case 6:
                printf("Enter Student ID: ");
                scanf("%d", &studentID);
                STUDENT_SCORE(studentID);
                break;

            case 7:
                printf("Enter Student ID to Search: ");
                scanf("%d", &studentID);
                SEARCH_STUDENT(studentID);
                break;

            case 8:
                printf("Average Score: %.2f\n", AVERAGE_SCORE());
                break;

            case 9:
                SORT_STUDENTS_BY_NAME();
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
