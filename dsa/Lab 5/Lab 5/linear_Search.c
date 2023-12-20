#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int num;
    struct node *next;
} Node;

Node *HEAD = NULL;

void create_node(int num)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("Allocation fault !!!!!");
        return;
    }

    newNode->num = num;

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
        printf("List is empty");
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

void search(int n)
{

    if (HEAD == NULL)
    {
        printf("List is empty !");
        return;
    }

    Node *temp = HEAD;

    int count = 0;
    while (temp)
    {
        if (temp->num == n)
        {
            printf("Element %d found on Index %d\n", n, count);
            // break;
        }
        temp = temp->next;
        count++;
    }
}
int main()
{

    while (true)
    {
        int ch;
        int n;
        int f;
        printf("Enter 1 to enter the elements\n");
        printf("Enter 2 to Search an element\n");
        printf("Enter 3 to disply\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            
            printf("Enter the number of elements: \n");
            scanf("%d", &n);
            printf("Enter a list of numbers : \n");

            for (int i = 0; i < n; i++)
            {
                int x;
                scanf("%d", &x);
                fflush(stdin);
                create_node(x);
            }
            break;

        case 2:
            
            printf("Enter the number to find: ");
            scanf("%d", &f);
            search(f);
            break;

        case 3:
            display();
            break;
        default:
            printf("Enter a valid Input");
            break;
        }
    }
}