#include <stdio.h>
#include <string.h>

#define ROWS 2
#define COLS 2

struct MenuItem
{
    char itemName[50];
    double itemPrice;
};

struct CanteenManagement
{
    struct MenuItem menuA[ROWS][COLS];
    struct MenuItem menuB[ROWS][COLS];
    struct MenuItem resultMatrixAdd[ROWS][COLS];
    struct MenuItem resultMatrixMultiply[ROWS][COLS];
};

void displayMatrix(struct MenuItem matrix[][COLS])
{
    printf("Matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%s(%.2f)\t", matrix[i][j].itemName, matrix[i][j].itemPrice);
        }
        printf("\n");
    }
}

void addMatrices(struct MenuItem matrixA[][COLS], struct MenuItem matrixB[][COLS], struct MenuItem resultMatrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            strcpy(resultMatrix[i][j].itemName, "Result");
            resultMatrix[i][j].itemPrice = matrixA[i][j].itemPrice + matrixB[i][j].itemPrice;
        }
    }
}

void multiplyMatrices(struct MenuItem matrixA[][COLS], struct MenuItem matrixB[][COLS], struct MenuItem resultMatrix[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            strcpy(resultMatrix[i][j].itemName, "Result");
            resultMatrix[i][j].itemPrice = matrixA[i][j].itemPrice * matrixB[i][j].itemPrice;
        }
    }
}

void addItem(struct MenuItem matrix[][COLS], int row, int col, const char itemName[], double itemPrice)
{
    strcpy(matrix[row][col].itemName, itemName);
    matrix[row][col].itemPrice = itemPrice;
}

void removeItem(struct MenuItem matrix[][COLS], int row, int col)
{
    strcpy(matrix[row][col].itemName, "");
    matrix[row][col].itemPrice = 0.0;
}

void searchItem(struct MenuItem matrix[][COLS], int row, int col, const char itemName[])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (strcmp(matrix[i][j].itemName, itemName) == 0)
            {
                printf("Item found: %s, Price: %.2f\n", matrix[i][j].itemName, matrix[i][j].itemPrice);
                return;
            }
        }
    }
    printf("Item not found in the menu.\n");
}

void fillMatrix(struct MenuItem matrix[][COLS])
{
    printf("Enter values for the matrix:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("Enter name for element [%d][%d]: ", i + 1, j + 1);
            scanf("%s", matrix[i][j].itemName);
            printf("Enter price for element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j].itemPrice);
        }
    }
}

int main()
{
    struct CanteenManagement canteen;

    printf("Enter values for Matrix A:\n");
    fillMatrix(canteen.menuA);

    printf("\nEnter values for Matrix B:\n");
    fillMatrix(canteen.menuB);

    
    printf("\nMatrix A:\n");
    displayMatrix(canteen.menuA);

    printf("\nMatrix B:\n");
    displayMatrix(canteen.menuB);


    addMatrices(canteen.menuA, canteen.menuB, canteen.resultMatrixAdd);
    printf("\nMatrix Addition Result:\n");
    displayMatrix(canteen.resultMatrixAdd);


    multiplyMatrices(canteen.menuA, canteen.menuB, canteen.resultMatrixMultiply);
    printf("\nMatrix Multiplication Result:\n");
    displayMatrix(canteen.resultMatrixMultiply);


    int choice, row, col;
    char itemName[50];
    double itemPrice;

    printf("\nMenu Item Operations:\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Search Item\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter row and column for the new item: ");
        scanf("%d %d", &row, &col);
        printf("Enter name for the new item: ");
        scanf("%s", itemName);
        printf("Enter price for the new item: ");
        scanf("%lf", &itemPrice);
        addItem(canteen.menuA, row - 1, col - 1, itemName, itemPrice);
        break;

    case 2:
        printf("Enter row and column to remove the item: ");
        scanf("%d %d", &row, &col);
        removeItem(canteen.menuA, row - 1, col - 1);
        break;

    case 3:
        printf("Enter name of the item to search: ");
        scanf("%s", itemName);
        searchItem(canteen.menuA, ROWS, COLS, itemName);
        break;

    default:
        printf("Invalid choice\n");
    }
    printf("\nUpdated Matrix A:\n");
    displayMatrix(canteen.menuA);

    return 0;
}
