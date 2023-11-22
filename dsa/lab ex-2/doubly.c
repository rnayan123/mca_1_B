#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 15

// Node structure for food item information
struct MenuItemNode
{
    char itemName[MAX_ITEM_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    struct MenuItemNode *next;
    struct MenuItemNode *prev;
};

typedef struct MenuItemNode MenuItemNode;

MenuItemNode *HEAD;

// Function to create a new menu item node
MenuItemNode *createMenuItemNode(const char *itemName, const char *price)
{
    MenuItemNode *newNode = (MenuItemNode *)malloc(sizeof(MenuItemNode));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->itemName, itemName, MAX_ITEM_NAME_LENGTH - 1);
    newNode->itemName[MAX_ITEM_NAME_LENGTH - 1] = '\0'; // Ensure null-terminated string

    strncpy(newNode->price, price, MAX_PRICE_LENGTH - 1);
    newNode->price[MAX_PRICE_LENGTH - 1] = '\0'; // Ensure null-terminated string

    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new menu item at the end of the doubly linked list
MenuItemNode *insertMenuItem(const char *itemName, const char *price)
{
    MenuItemNode *newNode = createMenuItemNode(itemName, price);

    if (HEAD == NULL)
    {
        // If the list is empty, make the new node the HEAD
        HEAD = newNode;
    }
    else
    {
        MenuItemNode *current = HEAD;

        // Traverse to the last node
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Insert the new node after the last node
        current->next = newNode;
        newNode->prev = current;
    }

    return HEAD;
}

// Function to delete a menu item by name
MenuItemNode *deleteMenuItem(const char *itemName)
{
    MenuItemNode *current = HEAD;
    while (current != NULL)
    {
        if (strcmp(current->itemName, itemName) == 0)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                HEAD = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            free(current);
            return HEAD;
        }
        current = current->next;
    }

    printf("Menu item '%s' not found in the menu.\n", itemName);
    return HEAD;
}

// Function to search for a menu item by name
void searchMenuItem(const char *itemName)
{
    MenuItemNode *current = HEAD;
    while (current != NULL)
    {
        if (strcmp(current->itemName, itemName) == 0)
        {
            printf("Menu Item Found: Name: %s, Price: %s\n", current->itemName, current->price);
            return;
        }
        current = current->next;
    }
    printf("Menu item '%s' not found in the menu.\n", itemName);
}

// Function to display all menu items in the doubly linked list
void displayMenu()
{
    MenuItemNode *current = HEAD;
    if (current == NULL)
    {
        printf("Menu is empty.\n");
        return;
    }

    printf("Menu Items:\n");
    while (current != NULL)
    {
        printf("Name: %s, Price: %s\n", current->itemName, current->price);
        current = current->next;
    }
}

// Function to free the memory occupied by the doubly linked list
void freeMenu()
{
    MenuItemNode *current = HEAD;
    while (current != NULL)
    {
        MenuItemNode *next = current->next;
        free(current);
        current = next;
    }
}



int main()
{
    MenuItemNode *menu = NULL;
    int choice;
    char itemName[MAX_ITEM_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];



    while (1)
    {
        printf("\nUniversity Canteen Management System (Doubly Linked List)\n");
        printf("1. Add Menu Item\n");
        printf("2. Delete Menu Item\n");
        printf("3. Search Menu Item\n");
        printf("4. Display Menu\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter menu item name to add: ");
            scanf("%s", itemName);
            printf("Enter the price: ");
            scanf("%s", price);
            HEAD = insertMenuItem(itemName, price);
            break;
        case 2:
            printf("Enter menu item name to delete: ");
            scanf("%s", itemName);
            HEAD = deleteMenuItem(itemName);
            break;
        case 3:
            printf("Enter menu item name to search: ");
            scanf("%s", itemName);
            searchMenuItem(itemName);
            break;
        case 4:
            displayMenu();
            break;
        case 5:
            freeMenu();
            printf("Exiting the program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
