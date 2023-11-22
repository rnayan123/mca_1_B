#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 15
#define MAX_QUANTITY_LENGTH 5

// Node structure for food item information
struct MenuItemNode
{
    char itemName[MAX_ITEM_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char quantity[MAX_QUANTITY_LENGTH];
    struct MenuItemNode *next;
};

typedef struct MenuItemNode MenuItemNode;

MenuItemNode *HEAD; // Head of the linked list

// Function to create a new menu item node
MenuItemNode *createMenuItemNode(const char *itemName, const char *price, const char *quantity)
{
    MenuItemNode *newNode = (MenuItemNode *)malloc(sizeof(MenuItemNode));
    if (newNode == NULL)
    {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->itemName, itemName, MAX_ITEM_NAME_LENGTH - 1);
    newNode->itemName[MAX_ITEM_NAME_LENGTH - 1] = '\0';

    strncpy(newNode->price, price, MAX_PRICE_LENGTH - 1);
    newNode->price[MAX_PRICE_LENGTH - 1] = '\0'; 

    strncpy(newNode->quantity, quantity, MAX_QUANTITY_LENGTH - 1);
    newNode->quantity[MAX_QUANTITY_LENGTH - 1] = '\0'; 

    newNode->next = NULL;
    return newNode;
}

// Function to insert a new menu item at the beginning of the linked list
MenuItemNode *insertMenuItem(const char *itemName, const char *price, const char *quantity)
{
    MenuItemNode *newNode = createMenuItemNode(itemName, price, quantity);
    newNode->next = HEAD;
    HEAD = newNode;
    return newNode;
}

// Function to delete a menu item by name
MenuItemNode *deleteMenuItem(const char *itemName)
{
    MenuItemNode *current = HEAD;
    MenuItemNode *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->itemName, itemName) == 0)
        {
            if (prev == NULL)
            {
                // Deleting the first node
                HEAD = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            return HEAD;
        }

        prev = current;
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
            printf("Menu Item Found: Name: %s, Price: %s, Quantity: %s\n", current->itemName, current->price, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Menu item '%s' not found in the menu.\n", itemName);
}

// Function to display all menu items in the linked list
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
        printf("Name: %s, Price: %s, Quantity: %s\n", current->itemName, current->price, current->quantity);
        current = current->next;
    }
}

// Function to free the memory occupied by the linked list
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
    char quantity[MAX_QUANTITY_LENGTH];


    while (1)
    {
        printf("\nUniversity Canteen Management System (Linked List)\n");
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
            printf("Enter the quantity: ");
            scanf("%s", quantity);
            menu = insertMenuItem(itemName, price, quantity);
            break;
        case 2:
            printf("Enter menu item name to delete: ");
            scanf("%s", itemName);
            menu = deleteMenuItem(itemName);
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
