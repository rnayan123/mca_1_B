#include <stdio.h>
#include <stdlib.h>

// Enum to represent data types
enum DataType
{
    INTEGER,
    CHARACTER
};

// Function to take user input for any data type
void getUserInput(void *arr, int size, int dataTypeSize, int (*inputFunction)(void *))
{
    for (int i = 0; i < size; i++)
    {
        inputFunction((char *)arr + i * dataTypeSize);
    }
}

// Function to perform Linear Search for any data type
int linearSearch(void *arr, int size, void *key, int dataTypeSize, int (*compare)(const void *, const void *))
{
    for (int i = 0; i < size; i++)
    {
        if (compare((char *)arr + i * dataTypeSize, key) == 0)
        {
            return i; // Key found, return index
        }
    }
    return -1; // Key not found
}

// Function to perform Sentinel Linear Search for any data type
int sentinelLinearSearch(void *arr, int size, void *key, int dataTypeSize, int (*compare)(const void *, const void *))
{
    char *arrChar = (char *)arr;
    int lastElementIndex = (size - 1) * dataTypeSize;

    char *lastElement = arrChar + lastElementIndex;

    for (int i = 0; i < dataTypeSize; i++)
    {
        lastElement[i] = *((char *)key + i); // Set sentinel
    }

    int i = 0;

    while (compare(arrChar + i * dataTypeSize, key) != 0)
    {
        i++;
    }

    for (int j = 0; j < dataTypeSize; j++)
    {
        lastElement[j] = arrChar[lastElementIndex + j]; // Reset last element
    }

    if (i < size - 1)
    {
        return i; // Key found, return index
    }
    else
    {
        return -1; // Key not found
    }
}

// Function to perform Binary Search for any data type
int binarySearch(void *arr, int size, void *key, int dataTypeSize, int (*compare)(const void *, const void *))
{
    char *arrChar = (char *)arr;

    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int compareResult = compare(arrChar + mid * dataTypeSize, key);

        if (compareResult == 0)
        {
            return mid; // Key found, return index
        }
        else if (compareResult < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Key not found
}

// Function to compare integers
int compareInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to compare characters
int compareChar(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

// Function to take user input for integers
int inputInt(void *element)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Consume any remaining characters in the input buffer
    printf("Enter an integer key: ");
    return scanf("%d", (int *)element) == 1;
}

// Function to take user input for characters
int inputChar(void *element)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ; // Consume any remaining characters in the input buffer

    printf("Enter a character key: ");
    return scanf(" %c", (char *)element) == 1; // Note the space before %c to consume leading whitespaces
}

int main()
{
    const int size = 10;
    int intArr[size];
    char charArr[size];
    void *key = NULL;

    int intSize = sizeof(int);
    int charSize = sizeof(char);

    int intArrSize = sizeof(intArr) / intSize;
    int charArrSize = sizeof(charArr) / charSize;

    int choice;
    int c; // Declare 'c' here

    do
    {
        printf("\nMenu:\n");
        printf("1. Choose data type\n");
        printf("2. Enter key\n");
        printf("3. Enter %d integers separated by spaces\n", size);
        printf("4. Enter %d characters separated by spaces\n", size);
        printf("5. Perform Linear Search\n");
        printf("6. Perform Sentinel Linear Search\n");
        printf("7. Perform Binary Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Choose data type:\n");
            printf("1. Integer\n");
            printf("2. Character\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                key = malloc(intSize);
            }
            else if (choice == 2)
            {
                key = malloc(charSize);
            }
            else
            {
                printf("Invalid choice.\n");
            }
            break;
        case 2:
            if (key != NULL)
            {
                if (choice == 1)
                {
                    printf("Enter an integer key: ");
                    while (!inputInt(key))
                    {
                        printf("Invalid input. Enter an integer key: ");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ; // Consume any remaining characters in the input buffer
                    }
                }
                else if (choice == 2)
                {
                    printf("Enter a character key: ");
                    while (!inputChar(key))
                    {
                        printf("Invalid input. Enter a character key: ");
                        while ((c = getchar()) != '\n' && c != EOF)
                            ; // Consume any remaining characters in the input buffer
                    }
                }
            }
            else
            {
                printf("Choose data type first.\n");
            }
            break;
        case 3:
            printf("Enter %d integers separated by spaces: ", size);
            getUserInput(intArr, size, intSize, inputInt);
            break;
        case 4:
            printf("Enter %d characters separated by spaces: ", size);
            getUserInput(charArr, size, charSize, inputChar);
            break;
        case 5:
            if (key != NULL)
            {
                int linearResult = linearSearch(intArr, intArrSize, key, intSize, compareInt);
                if (linearResult != -1)
                {
                    printf("Linear Search: Element found at index %d.\n", linearResult);
                }
                else
                {
                    printf("Linear Search: Element not found.\n");
                }
            }
            else
            {
                printf("Enter key first.\n");
            }
            break;
        case 6:
            if (key != NULL)
            {
                int sentinelResult = sentinelLinearSearch(charArr, charArrSize, key, charSize, compareChar);
                if (sentinelResult != -1)
                {
                    printf("Sentinel Linear Search: Element found at index %d.\n", sentinelResult);
                }
                else
                {
                    printf("Sentinel Linear Search: Element not found.\n");
                }
            }
            else
            {
                printf("Enter key first.\n");
            }
            break;
        case 7:
            if (key != NULL)
            {
                int binaryResult = binarySearch(intArr, intArrSize, key, intSize, compareInt);
                if (binaryResult != -1)
                {
                    printf("Binary Search: Element found at index %d.\n", binaryResult);
                }
                else
                {
                    printf("Binary Search: Element not found.\n");
                }
            }
            else
            {
                printf("Enter key first.\n");
            }
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free(key);

    return 0;
}
