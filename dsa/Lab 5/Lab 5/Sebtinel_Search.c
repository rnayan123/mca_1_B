#include <stdio.h>
#include <string.h>

int elementComparisons = 0;

int sentinelSearchInt(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
        elementComparisons++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) {
        return i;
    }

    else
    printf("element not found");
}

int sentinelSearchChar(char arr[], int n, char key) {
    char last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        i++;
        elementComparisons++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) {
        return i;
    }

    return -1;
}


int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the data type (int or char): ");
    char dataType[4];
    scanf("%s", dataType);

    if (strcmp(dataType, "int") == 0) {

        int intArray[n];
        printf("Enter %d integer elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &intArray[i]);
        }

        int key;
        printf("Enter the key to search: ");
        scanf("%d", &key);

        int sentinelIndex = sentinelSearchInt(intArray, n, key);
        printf("Sentinel Search: Element comparisons = %d\n", elementComparisons);

    } else if (strcmp(dataType, "char") == 0) {

        char charArray[n];
        printf("Enter %d character elements:\n", n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &charArray[i]);
        }

        char key;
        printf("Enter the key to search: ");
        scanf(" %c", &key);

        int sentinelIndex = sentinelSearchChar(charArray, n, key);
        printf("Sentinel Search: Element comparisons = %d\n", elementComparisons);

    } else {
        printf("Invalid data type entered. Please enter 'int' or 'char'.\n");
        return 1;
    }

    return 0;
}
