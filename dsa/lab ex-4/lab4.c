#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct FoodOrder
{
    char itemName[50];
    int quantity;
};

struct InventoryItem
{
    char itemName[50];
};

struct CircularQueue
{
    struct FoodOrder *orders;
    int front, rear, size, capacity;
};


struct Deque
{
    struct InventoryItem *items;
    int front, rear, size, capacity;
};


void initializeCircularQueue(struct CircularQueue *circularQueue, int capacity)
{
    circularQueue->orders = (struct FoodOrder *)malloc(capacity * sizeof(struct FoodOrder));
    circularQueue->front = circularQueue->rear = -1;
    circularQueue->size = 0;
    circularQueue->capacity = capacity;
}


void initializeDeque(struct Deque *deque, int capacity)
{
    deque->items = (struct InventoryItem *)malloc(capacity * sizeof(struct InventoryItem));
    deque->front = deque->rear = -1;
    deque->size = 0;
    deque->capacity = capacity;
}

// Function to check if the circular queue is empty
int isCircularQueueEmpty(struct CircularQueue *circularQueue)
{
    return circularQueue->size == 0;
}

// Function to check if the circular queue is full
int isCircularQueueFull(struct CircularQueue *circularQueue)
{
    return circularQueue->size == circularQueue->capacity;
}

// Function to enqueue a food order to the circular queue
void enqueueOrder(struct CircularQueue *circularQueue, struct FoodOrder order)
{
    if (isCircularQueueFull(circularQueue))
    {
        printf("Order queue is full. Cannot add more orders.\n");
        return;
    }

    if (isCircularQueueEmpty(circularQueue))
        circularQueue->front = 0;

    circularQueue->rear = (circularQueue->rear + 1) % circularQueue->capacity;
    circularQueue->orders[circularQueue->rear] = order;
    circularQueue->size++;

    printf("Order added to the queue: Item: %s, Quantity: %d\n", order.itemName, order.quantity);
}

// Function to dequeue a food order from the circular queue
void dequeueOrder(struct CircularQueue *circularQueue)
{
    if (isCircularQueueEmpty(circularQueue))
    {
        printf("Order queue is empty. No orders to dequeue.\n");
        return;
    }

    printf("Order dequeued: Item: %s, Quantity: %d\n", circularQueue->orders[circularQueue->front].itemName, circularQueue->orders[circularQueue->front].quantity);

    if (circularQueue->front == circularQueue->rear)
        circularQueue->front = circularQueue->rear = -1;
    else
        circularQueue->front = (circularQueue->front + 1) % circularQueue->capacity;

    circularQueue->size--;
}

// Function to display the food orders in the circular queue
void displayOrderQueue(struct CircularQueue *circularQueue)
{
    if (isCircularQueueEmpty(circularQueue))
    {
        printf("Order queue is empty.\n");
        return;
    }

    int index = circularQueue->front;
    do
    {
        printf("Order: Item: %s, Quantity: %d\n", circularQueue->orders[index].itemName, circularQueue->orders[index].quantity);
        index = (index + 1) % circularQueue->capacity;
    } while (index != (circularQueue->rear + 1) % circularQueue->capacity);
}

// Function to check if the deque is empty
int isDequeEmpty(struct Deque *deque)
{
    return deque->size == 0;
}

// Function to check if the deque is full
int isDequeFull(struct Deque *deque)
{
    return deque->size == deque->capacity;
}

// Function to enqueue an item to the rear of the deque
void enqueueRearInventory(struct Deque *deque, struct InventoryItem item)
{
    if (isDequeFull(deque))
    {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    if (isDequeEmpty(deque))
        deque->front = deque->rear = 0;
    else
        deque->rear = (deque->rear + 1) % deque->capacity;

    deque->items[deque->rear] = item;
    deque->size++;

    printf("Item added to the inventory: Item: %s\n", item.itemName);
}

// Function to enqueue an item to the front of the deque
void enqueueFrontInventory(struct Deque *deque, struct InventoryItem item)
{
    if (isDequeFull(deque))
    {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    if (isDequeEmpty(deque))
        deque->front = deque->rear = 0;
    else
        deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;

    deque->items[deque->front] = item;
    deque->size++;

    printf("Item added to the front of the inventory: Item: %s\n", item.itemName);
}

// Function to dequeue an item from the rear of the deque
void dequeueRearInventory(struct Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("Inventory is empty. No items to dequeue.\n");
        return;
    }

    printf("Item dequeued from Rear of Inventory: Item: %s\n", deque->items[deque->rear].itemName);

    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else
        deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;

    deque->size--;
}

// Function to dequeue an item from the front of the deque
void dequeueFrontInventory(struct Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("Inventory is empty. No items to dequeue.\n");
        return;
    }

    printf("Item dequeued from Front of Inventory: Item: %s\n", deque->items[deque->front].itemName);

    if (deque->front == deque->rear)
        deque->front = deque->rear = -1;
    else
        deque->front = (deque->front + 1) % deque->capacity;

    deque->size--;
}

// Function to display the items in the deque
void displayInventory(struct Deque *deque)
{
    if (isDequeEmpty(deque))
    {
        printf("Inventory is empty.\n");
        return;
    }

    int index = deque->front;
    do
    {
        printf("Item: %s\n", deque->items[index].itemName);
        index = (index + 1) % deque->capacity;
    } while (index != (deque->rear + 1) % deque->capacity);
}

void freeMemory(struct CircularQueue *circularQueue, struct Deque *deque)
{
    free(circularQueue->orders);
    free(deque->items);
}


int main()
{
    struct CircularQueue orderQueue;
    struct Deque inventoryDeque;

    int choice;
    initializeCircularQueue(&orderQueue, 5);
    initializeDeque(&inventoryDeque, 5);

    do
    {
        printf("\nCanteen Management Menu:\n");
        printf("1. Place Order\n");
        printf("2. Serve Order\n");
        printf("3. View Next Order\n");
        printf("4. View Order Queue\n");
        printf("5. Add Item to Inventory\n");
        printf("6. Add Item to Front of Inventory\n");
        printf("7. Remove Item from Rear of Inventory\n");
        printf("8. Remove Item from Front of Inventory\n");
        printf("9. View Front of Inventory\n");
        printf("10. View Rear of Inventory\n");
        printf("11. View Inventory\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char itemName[50];
            int quantity;
            printf("Enter food item name for the order: ");
            scanf("%s", itemName);
            printf("Enter quantity for the order: ");
            scanf("%d", &quantity);
            struct FoodOrder order;
            strcpy(order.itemName, itemName);
            order.quantity = quantity;
            enqueueOrder(&orderQueue, order);
            break;
        }
        case 2:
            dequeueOrder(&orderQueue);
            break;
        case 3:
            printf("Next Order: ");
            if (!isCircularQueueEmpty(&orderQueue))
            {
                printf("Item: %s, Quantity: %d\n", orderQueue.orders[orderQueue.front].itemName, orderQueue.orders[orderQueue.front].quantity);
            }
            else
            {
                printf("No orders in the queue.\n");
            }
            break;
        case 4:
            displayOrderQueue(&orderQueue);
            break;
        case 5:
        {
            char itemName[50];
            printf("Enter item name to add to inventory: ");
            scanf("%s", itemName);
            struct InventoryItem item;
            strcpy(item.itemName, itemName);
            enqueueRearInventory(&inventoryDeque, item);
            break;
        }
        case 6:
        {
            char itemName[50];
            printf("Enter item name to add to front of inventory: ");
            scanf("%s", itemName);
            struct InventoryItem item;
            strcpy(item.itemName, itemName);
            enqueueFrontInventory(&inventoryDeque, item);
            break;
        }
        case 7:
            dequeueRearInventory(&inventoryDeque);
            break;
        case 8:
            dequeueFrontInventory(&inventoryDeque);
            break;
        case 9:
            printf("Front of Inventory: ");
            if (!isDequeEmpty(&inventoryDeque))
            {
                printf("Item: %s\n", inventoryDeque.items[inventoryDeque.front].itemName);
            }
            else
            {
                printf("Inventory is empty.\n");
            }
            break;
        case 10:
            printf("Rear of Inventory: ");
            if (!isDequeEmpty(&inventoryDeque))
            {
                printf("Item: %s\n", inventoryDeque.items[inventoryDeque.rear].itemName);
            }
            else
            {
                printf("Inventory is empty.\n");
            }
            break;
        case 11:
            displayInventory(&inventoryDeque);
            break;
        case 0:
            printf("Exiting the canteen management program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    // Free allocated memory
    freeMemory(&orderQueue, &inventoryDeque);

    return 0;
}
