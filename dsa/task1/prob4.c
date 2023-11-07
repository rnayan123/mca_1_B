#include <stdio.h>
#include <string.h>

// Function prototypes
void read(char (*names)[50], int n);
void display(char (*names)[50], int n);
 void bubbleSortNames(char (*names)[50], int n);

int main()
{
    int n;
    printf("Enter the number of names: ");
    scanf("%d", &n);

    char names[n][50];

    read(names, n);
    printf("the entered names are\n");
    display(names,n);
    bubbleSortNames(names, n);

    printf("\nSorted names:\n");
    display(names, n);

    return 0;
}

void read(char (*names)[50], int n)
{
    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

   
}
void display(char (*names)[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", names[i]);
    }
}

void bubbleSortNames(char (*names)[50], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                // Swap names if they are in the wrong order
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}
