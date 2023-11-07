#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL; 

void beginsert(int);
void displayList();

int main()
{
    int choice, item;
    do
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d", &item);
        beginsert(item);
        printf("\nPress 0 to insert more?\n");
        scanf("%d", &choice);
    } while (choice == 0);

    displayList();
    return 0;
}

void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

void displayList()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty\n");
        return;
    }
    printf("\nUpdated List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
