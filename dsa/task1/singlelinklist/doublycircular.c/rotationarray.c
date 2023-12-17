#include <stdio.h>

int main()
{
    int a[] = { 4,1,2,3 };
    int b = sizeof(a) / sizeof(a[0]);

     for (int i = 1; i < b; i++)
    {
        if (a[i - 1] > a[i])
        {
            printf("%d \n", b- i);
            break;
        }
    }
}