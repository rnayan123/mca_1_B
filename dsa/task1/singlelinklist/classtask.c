#include <stdio.h>

typedef struct passenger
{
    int passenger_no;
    char name[26];
    float price;
} passenger;

passenger p[5];
int len = sizeof(p) / sizeof(p[0]);

void read();
void display();

int main()
{
    int ch;
    printf("Enter your choice:\n");
    printf("1. for read\n");
    printf("2. for display\n");
    printf("3. for search\n");
    scanf("%d", &ch); 

    switch (ch)
    {
    case 1:
        read();
        break;
    case 2:
        display();
        break;
    // case 3:
    //     search();
    //     break;
    default:
        printf("Invalid choice\n");
    }

    return 0;
}

void read()
{
    for (int i = 0; i < len; i++)
    {
        printf("Enter the passenger no: ");
        scanf("%d", &p[i].passenger_no);
        printf("Enter the name: ");
        scanf("%s", p[i].name);
        printf("Enter the price: ");
        scanf("%f", &p[i].price);
    
    }
}

void display()
{
    for (int i = 0; i < len; i++)
    {
        printf("Passenger no.: %d\n", p[i].passenger_no);
        printf("Name: %s\n", p[i].name);
        printf("Price: %.2f\n", p[i].price);
    }
}
