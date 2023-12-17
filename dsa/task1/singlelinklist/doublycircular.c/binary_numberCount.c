#include <stdio.h>

int main()
{
    int arr[10] = {2, 5, 5, 5, 6, 6, 8, 9, 9, 9};
    int target = 6;

    int low = 0;
    int high = 9;
    int first = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    low = 0;
    high = 9;
    int last = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("the count is %d \n", last - first + 1);
}