#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int num;
    struct node *next;
} Node;

Node *HEAD = NULL;

void insertNode(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    newNode->num = num;
    newNode->next = NULL;

    if (HEAD == NULL)
    {
        HEAD = newNode;
    }
    else
    {
        Node *temp = HEAD;

        while (temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void display()
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = HEAD;

    while (temp)
    {
        printf("%d -> ", temp->num);
        temp = temp->next;
    }

    printf("X\n");
}

bool linearSearch(int key)
{
    if (HEAD == NULL)
    {
        printf("List is empty\n");
        return false;
    }

    Node *temp = HEAD;

    while (temp)
    {
        if (temp->num == key)
        {
            return true; // Element found
        }
        temp = temp->next;
    }

    return false; // Element not found
}

void cleanup()
{
    Node *temp = HEAD;
    while (HEAD)
    {
        temp = HEAD;
        HEAD = HEAD->next;
        free(temp);
    }
    // Set HEAD to NULL after freeing all nodes
    HEAD = NULL;
}

int main()
{
    bool isRunning = true;

    while (isRunning)
    {
        int choice;
        int num;
        int key;

        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Search an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &num);
            insertNode(num);
            break;

        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            if (linearSearch(key))
            {
                printf("Element %d found in the list.\n", key);
            }
            else
            {
                printf("Element %d not found in the list.\n", key);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            cleanup();
            isRunning = false;
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

