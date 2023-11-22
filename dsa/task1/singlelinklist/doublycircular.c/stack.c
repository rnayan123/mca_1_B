#include <stdio.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow - Cannot push %d, stack is full.\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow - Cannot pop, stack is empty.\n");
        return -1; // indicating underflow
    }
    else
    {
        printf("%d popped from stack\n", stack[top]);
        return stack[top--];
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; ++i)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    do
    {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
