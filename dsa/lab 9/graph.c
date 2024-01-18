#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct FoodItem
{
    char name[100];
    float price;
};

struct FoodItem items[MAX_ITEMS];
int itemMatrix[MAX_ITEMS][MAX_ITEMS] = {0}; // Initialize the matrix with zeros
int numItems = 0;

void displayItems()
{
    printf("Food Items:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%d: %s, Price: %.2f\n", i + 1, items[i].name, items[i].price);
    }
}

void addItem()
{
    if (numItems < MAX_ITEMS)
    {
        struct FoodItem newItem;
        printf("Enter Food Item Name: ");
        scanf("%s", newItem.name);
        printf("Enter Food Item Price: ");
        scanf("%f", &newItem.price);

        items[numItems] = newItem;
        numItems++;
        printf("Food Item added successfully!\n");
    }
    else
    {
        printf("Cannot add more food items. Maximum limit reached.\n");
    }
}

void displayConnections()
{
    printf("Food Item Connections:\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%s is connected to: ", items[i].name);
        for (int j = 0; j < numItems; j++)
        {
            if (itemMatrix[i][j] == 1)
            {
                printf("%s, ", items[j].name);
            }
        }
        printf("\n");
    }
}

void addConnections()
{
    printf("Enter the adjacency matrix to represent connections (0 or 1):\n");

    for (int i = 0; i < numItems; i++)
    {
        for (int j = 0; j < numItems; j++)
        {
            printf("Is %s connected to %s? (1 for yes, 0 for no): ", items[i].name, items[j].name);
            scanf("%d", &itemMatrix[i][j]);
        }
    }

    printf("Connections added successfully!\n");
}

// Breadth-First Search
void BFS(int start)
{
    printf("Breadth-First Search starting from %s:\n", items[start - 1].name);

    int visited[MAX_ITEMS] = {0};
    int queue[MAX_ITEMS];
    int front = -1, rear = -1;

    visited[start - 1] = 1;
    queue[++rear] = start - 1;

    while (front != rear)
    {
        int current = queue[++front];
        printf("%s, ", items[current].name);

        for (int i = 0; i < numItems; i++)
        {
            if (itemMatrix[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }

    printf("\n");
}

// Depth-First Search
void DFS(int start, int visited[])
{
    printf("%s, ", items[start].name);
    visited[start] = 1;

    for (int i = 0; i < numItems; i++)
    {
        if (itemMatrix[start][i] == 1 && !visited[i])
        {
            DFS(i, visited);
        }
    }
}

void DFSWrapper(int start)
{
    printf("Depth-First Search starting from %s:\n", items[start - 1].name);

    int visited[MAX_ITEMS] = {0};
    DFS(start - 1, visited);

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\nCanteen Management System\n");
        printf("1. Add Food Item\n");
        printf("2. Display Food Items\n");
        printf("3. Add Connection\n");
        printf("4. Display Connections\n");
        printf("5. Perform Breadth-First Search\n");
        printf("6. Perform Depth-First Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n; // Declare n at the beginning of the block
            printf("Enter the number of food items: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                addItem();
            }
            break;
        }
        case 2:
            displayItems();
            break;
        case 3:
            addConnections();
            break;
        case 4:
            displayConnections();
            break;
        case 5:
        {
            int startNode;
            printf("Enter the starting food item number for BFS: ");
            scanf("%d", &startNode);
            BFS(startNode);
            break;
        }
        case 6:
        {
            int startNode;
            printf("Enter the starting food item number for DFS: ");
            scanf("%d", &startNode);
            DFSWrapper(startNode);
            break;
        }
        case 7:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
