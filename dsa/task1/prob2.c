#include <stdio.h>

void readMatrix(int (*arr)[10], int n);
void displayMatrix(int (*arr)[10], int n);
int calculateRowTotal(int (*arr)[10], int n, int row);
int isIdentityMatrix(int (*arr)[10], int n);

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int arr[10][10];

    printf("Enter the elements of the matrix:\n");
    readMatrix(arr, n);

    printf("The elements are:\n");
    displayMatrix(arr, n);

    int rowToCalculate = 0;
    int rowTotal = calculateRowTotal(arr, n, rowToCalculate);
    printf("Total of Row %d: %d\n", rowToCalculate + 1, rowTotal);

    
    if (isIdentityMatrix(arr, n))
    {
        printf("The matrix is an identity matrix.\n");
    }
    else
    {
        printf("The matrix is not an identity matrix.\n");
    }

    return 0;
}

void readMatrix(int (*arr)[10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", (*(arr + i) + j));
        }
    }
}

void displayMatrix(int (*arr)[10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

int calculateRowTotal(int (*arr)[10], int n, int row)
{
    int total = 0;
    for (int j = 0; j < n; ++j)
    {
        total += *(*(arr + row) + j);
    }
    return total;
}

int isIdentityMatrix(int (*arr)[10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i == j && *(*(arr + i) + j) != 1) || (i != j && *(*(arr + i) + j) != 0))
            {
                return 0; 
            }
        }
    }
    return 1; 
}
