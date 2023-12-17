#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for a character node in the deque
struct Node
{
    char data;
    struct Node *next;
};

// Deque structure for the linked list implementation
struct Deque
{
    struct Node *front;
    struct Node *rear;
};

// Function to initialize the deque
void initializeDeque(struct Deque *deque)
{
    deque->front = deque->rear = NULL;
}

// Function to check if the deque is empty
int isDequeEmpty(struct Deque *deque)
{
    return deque->front == NULL;
}

// Function to enqueue a character to the rear of the deque
void enqueueRear(struct Deque *deque, char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isDequeEmpty(deque))
    {
        deque->front = deque->rear = newNode;
    }
    else
    {
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to dequeue a character from the front of the deque
char dequeueFront(struct Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("Deque is empty.\n");
        return '\0'; // Return null character for an empty deque
    }

    struct Node *temp = deque->front;
    char data = temp->data;

    if (deque->front == deque->rear)
    {
        deque->front = deque->rear = NULL;
    }
    else
    {
        deque->front = temp->next;
    }

    free(temp);
    return data;
}

// Function to check if a string is a palindrome using a deque

int isPalindrome(struct Deque *deque, const char *str)
{
    int length = strlen(str);

    // Enqueue characters to the rear of the deque
    for (int i = 0; i < length; i++)
    {
        enqueueRear(deque, str[i]);
    }

    // Dequeue and compare characters from both ends
    for (int i = 0; i < length; i++)
    {
        char frontChar = dequeueFront(deque);
        char rearChar = str[length - i - 1];

        if (frontChar != rearChar)
        {
            return 0; // Not a palindrome
        }
    }

    return 1; 
}

// Function to free the allocated memory for the deque
void freeDeque(struct Deque *deque)
{
    while (!isDequeEmpty(deque))
    {
        dequeueFront(deque);
    }
}

int main()
{
    struct Deque deque;
    initializeDeque(&deque);

    char input[100];

    printf("Enter a string to check if it is a palindrome: ");
    scanf("%s", input);

    if (isPalindrome(&deque, input))
    {
        printf("%s is a palindrome.\n", input);
    }
    else
    {
        printf("%s is not a palindrome.\n", input);
    }

    // Free allocated memory
    freeDeque(&deque);

    return 0;
}
