#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *dynamicArray;
    int size = 5;
    int sum = 0;

    dynamicArray = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &dynamicArray[i]);
    }

    for (int i = 0; i < size; i++)
    {
        sum = sum + dynamicArray[i];
        printf("%d\t", sum);
    }

    free(dynamicArray); 

    return 0;
}
