#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to the queue.\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node *temp = queue->front;
    int item = temp->data;

    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    return item;
}

void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int calculateSum(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Sum is 0.\n");
        return 0;
    }

    int sum = 0;
    struct Node *current = queue->front;
    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }

    printf("Sum of queue elements: %d\n", sum);
    return sum;
}

void calculateAverage(struct Queue *queue)
{
    int sum = calculateSum(queue);
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot calculate average.\n");
        return;
    }

    int count = 0;
    struct Node *current = queue->front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    double average = (double)sum / count;

    printf("Average of queue elements: %.2lf\n", average);
}

int calculateCount(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Count is 0.\n");
        return 0;
    }

    int count = 0;
    struct Node *current = queue->front;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("Number of elements in the queue: %d\n", count);
    return count;
}

int findMaxElement(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. No maximum element.\n");
        return -1;
    }

    int maxElement = queue->front->data;
    struct Node *current = queue->front->next;

    while (current != NULL)
    {
        if (current->data > maxElement)
        {
            maxElement = current->data;
        }
        current = current->next;
    }

    printf("Maximum element in the queue: %d\n", maxElement);
    return maxElement;
}

int main()
{
    struct Queue *queue = createQueue();
    int choice, item;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Calculate Sum\n");
        printf("5. Calculate Average\n");
        printf("6. Calculate Count\n");
        printf("7. Find Maximum Element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            item = dequeue(queue);
            if (item != -1)
                printf("Dequeued element: %d\n", item);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            calculateSum(queue);
            break;
        case 5:
            calculateAverage(queue);
            break;
        case 6:
            calculateCount(queue);
            break;
        case 7:
            findMaxElement(queue);
            break;
        case 8:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 8);

    struct Node *current = queue->front;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(queue);

    return 0;
}
