#include <stdio.h>

int main()
{
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", arr[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
