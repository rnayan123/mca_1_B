#include <stdio.h>

void bubble_sort(int arr[], int n, int *comparisons, int *swaps) {
    *comparisons = 0;
    *swaps = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                (*swaps)++;
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n, int *comparisons, int *shifts) {
    *comparisons = 0;
    *shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        (*comparisons)++;

        while (j >= 0 && key < arr[j]) {
            (*comparisons)++;
            (*shifts)++;
            // Shift
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


int main() {
    int data[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(data) / sizeof(data[0]);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int bubble_comparisons, bubble_swaps;
                bubble_sort(data, n, &bubble_comparisons, &bubble_swaps);
                printf("Bubble Sort: Comparisons - %d, Swaps - %d\n", bubble_comparisons, bubble_swaps);
                break;
            }
            case 2: {
                int insertion_comparisons, insertion_shifts;
                insertion_sort(data, n, &insertion_comparisons, &insertion_shifts);
                printf("Insertion Sort: Comparisons - %d, Shifts - %d\n", insertion_comparisons, insertion_shifts);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
