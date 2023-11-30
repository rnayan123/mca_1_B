#include <stdio.h>

void m(int *p)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", p[i]);
    }
}

int main()
{
    int a[5] = {6, 5, 3, 2, 1};
    m(&a);
}