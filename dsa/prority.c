#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct patient
{
    int patientID;
    char name[50];
    int age;
    int priority; // Priority based on medical condition
    struct patient *link;
} Patient;

Patient *front = NULL;

// Insert method
void admitPatient(int patientID, char name[], int age, int priority)
{
    Patient *temp, *q;

    temp = (Patient *)malloc(sizeof(Patient));
    temp->patientID = patientID;
    strcpy(temp->name, name);
    temp->age = age;
    temp->priority = priority;

    // Condition to check whether the first patient is empty or the patient to be admitted has higher priority than the first patient
    if (front == NULL || priority < front->priority)
    {
        temp->link = front;
        front = temp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
            q = q->link;
        temp->link = q->link;
        q->link = temp;
    }
}

// Discharge method based on priority
void dischargePatient()
{
    Patient *temp;
    // Condition to check whether the queue of patients is empty or not
    if (front == NULL)
        printf("No patients to discharge.\n");
    else
    {
        temp = front;
        printf("Discharged patient ID: %d, Name: %s, Age: %d\n", temp->patientID, temp->name, temp->age);
        front = front->link;
        free(temp);
    }
}

// Display method
void displayPatients()
{
    Patient *ptr;
    ptr = front;
    if (front == NULL)
        printf("No patients in the hospital.\n");
    else
    {
        printf("List of Patients:\n");
        printf("Patient ID    Name               Age      Priority\n");
        while (ptr != NULL)
        {
            printf("%10d   %-20s   %5d   %5d\n", ptr->patientID, ptr->name, ptr->age, ptr->priority);
            ptr = ptr->link;
        }
    }
}

// Main method
int main()
{
    int choice, patientID, age, priority;
    char name[50];

    do
    {
        printf("\n1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Display Patients\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter patient details:\n");
            printf("Patient ID: ");
            scanf("%d", &patientID);
            printf("Name: ");
            scanf("%s", name);
            printf("Age: ");
            scanf("%d", &age);
            printf("Priority (1-10, 10 being highest): ");
            scanf("%d", &priority);
            admitPatient(patientID, name, age, priority);
            break;
        case 2:
            dischargePatient();
            break;
        case 3:
            displayPatients();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
