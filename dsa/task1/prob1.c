#include <stdio.h>

void readAndDisplay(int *arr, int n);
void displayOddPositioned(int *arr, int n);
void displayEvenNumbers(int *arr, int n);
void displayMaximumNumber(int *arr, int n);
void calculateSumAndAverage(int *arr, int n);

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    readAndDisplay(arr, n);

    printf("Odd positioned elements:\n");
    displayOddPositioned(arr, n);

    printf("Even numbers:\n");
    displayEvenNumbers(arr, n);

    printf("Maximum number:\n");
    displayMaximumNumber(arr, n);

    printf("Sum and Average:\n");
    calculateSumAndAverage(arr, n);

    return 0;
}

void readAndDisplay(int *arr, int n)
{
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Entered numbers: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayOddPositioned(int *arr, int n)
{
    printf("Odd positioned elements: ");
    for (int i = 1; i < n; i += 2)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void displayEvenNumbers(int *arr, int n)
{
    printf("Even numbers: ");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void displayMaximumNumber(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Maximum number: %d\n", max);
}

void calculateSumAndAverage(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    float average = (float)sum / n;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
}
