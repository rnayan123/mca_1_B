#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEMS 10

typedef struct MenuItem
{
    char name[MAX_ITEM_NAME_LENGTH];
    float price;
} MenuItem;

MenuItem menu[MAX_ITEMS];

int compareCount = 0;
int transferCount = 0;

void resetCounters()
{
    compareCount = 0;
    transferCount = 0;
}

void displayCounters()
{
    printf("Number of Comparisons: %d\n", compareCount);
    printf("Number of Data Transfers: %d\n", transferCount);
}

void generateRandomMenu()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        sprintf(menu[i].name, "Item%d", i + 1);
        menu[i].price = (rand() % 1000) / 100.0; // Random price between 0 and 10
    }
}

void writeMenuToFile(const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        fprintf(file, "%s,%.2f\n", menu[i].name, menu[i].price);
    }

    fclose(file);
}

void readMenuFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (fscanf(file, "%[^,],%f", menu[i].name, &menu[i].price) != 2)
        {
            printf("Error reading from file.\n");
            break;
        }
    }

    fclose(file);
}

void printMenu()
{
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        printf("Item: %s, Price: $%.2f\n", menu[i].name, menu[i].price);
    }
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    MenuItem L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = menu[l + i];
    for (j = 0; j < n2; j++)
        R[j] = menu[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].price <= R[j].price)
        {
            menu[k] = L[i];
            i++;
        }
        else
        {
            menu[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        menu[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        menu[k] = R[j];
        j++;
        k++;
    }

    compareCount += n1 + n2 - 1;
    transferCount += n1 + n2;
}

void mergeSort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int partition(int low, int high)
{
    MenuItem pivot = menu[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (menu[j].price <= pivot.price)
        {
            i++;
            MenuItem temp = menu[i];
            menu[i] = menu[j];
            menu[j] = temp;
        }
    }

    MenuItem temp = menu[i + 1];
    menu[i + 1] = menu[high];
    menu[high] = temp;

    return (i + 1);
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
    compareCount += high - low;
    transferCount += high - low;
}
int main()
{
    int choice;

    generateRandomMenu();

    do
    {
        printf("\nUniversity Canteen Management System\n");
        printf("1. Generate Random Menu\n");
        printf("2. Write Menu to File\n");
        printf("3. Read Menu from File\n");
        printf("4. Print Menu\n");
        printf("5. Merge Sort Menu\n");
        printf("6. Quick Sort Menu\n");
        printf("7. Display Sorting Statistics\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            generateRandomMenu();
            printf("Random Menu Generated.\n");
            break;
        case 2:
            writeMenuToFile("unsorted_menu.txt");
            printf("Menu Written to File.\n");
            break;
        case 3:
            readMenuFromFile("unsorted_menu.txt");
            printf("Menu Read from File.\n");
            break;
        case 4:
            printMenu();
            break;
        case 5:
            mergeSort(0, MAX_ITEMS - 1);
            printf("Menu Sorted using Merge Sort.\n");
            break;
        case 6:
            quickSort(0, MAX_ITEMS - 1);
            printf("Menu Sorted using Quick Sort.\n");
            break;
        case 7:
            displayCounters();
            break;
        case 8:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
