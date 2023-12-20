#include <stdio.h>
#include <string.h>

int elementComparisons = 0;
int indexComparisons = 0;


int binarySearchInt(int arr[], int low, int high, int key) {
    while (low <= high) {
        indexComparisons ++;
        int mid = low + (high - low) / 2;

        elementComparisons++;
        if (arr[mid] == key) {  
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int binarySearchChar(char arr[], int low, int high, char key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        elementComparisons++;
        if (arr[mid] == key) {
            indexComparisons += mid + 1;
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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
        printf("Enter %d sorted integer elements of the array:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &intArray[i]);
        }

        int key;
        printf("Enter the key to search: ");
        scanf("%d", &key);

        int binaryIndex = binarySearchInt(intArray, 0, n - 1, key);
        printf("Binary Search: Element comparisons = %d, Index comparisons = %d\n", elementComparisons, indexComparisons);

    } else if (strcmp(dataType, "char") == 0) {

        char charArray[n];
        printf("Enter %d sorted character elements of the array:\n", n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &charArray[i]);
        }

        char key;
        printf("Enter the key to search: ");
        scanf(" %c", &key);

        int binaryIndex = binarySearchChar(charArray, 0, n - 1, key);
        printf("Binary Search: Element comparisons = %d, Index comparisons = %d\n", elementComparisons, indexComparisons);
    } else {
        printf("Invalid data type entered. Please enter 'int' or 'char'.\n");
        return 1;
    }

    return 0;
}