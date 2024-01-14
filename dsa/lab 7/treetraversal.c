#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[20];
} Contact;

typedef struct TreeNode
{
    Contact contact;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct QueueNode
{
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

TreeNode *root = NULL;

TreeNode *createTreeNode(Contact contact)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->contact = contact;
    newNode->left = newNode->right = NULL;
    return newNode;
}

QueueNode *createQueueNode(TreeNode *treeNode)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    return newNode;
}

Queue *initializeQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}

void enqueue(Queue *queue, TreeNode *treeNode)
{
    QueueNode *newNode = createQueueNode(treeNode);
    if (isQueueEmpty(queue))
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

TreeNode *dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        return NULL;
    }
    QueueNode *frontNode = queue->front;
    TreeNode *treeNode = frontNode->treeNode;
    queue->front = frontNode->next;
    free(frontNode);
    return treeNode;
}

void insertContactLevelOrder(Contact contact)
{
    TreeNode *newNode = createTreeNode(contact);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    Queue *queue = initializeQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue))
    {
        TreeNode *current = dequeue(queue);

        if (current->left == NULL)
        {
            current->left = newNode;
            break;
        }
        else
        {
            enqueue(queue, current->left);
        }

        if (current->right == NULL)
        {
            current->right = newNode;
            break;
        }
        else
        {
            enqueue(queue, current->right);
        }
    }

    free(queue);
}

TreeNode *insertContactHelper(TreeNode *node, Contact contact)
{
    if (node == NULL)
    {
        return createTreeNode(contact);
    }

    int compareResult = strcmp(contact.name, node->contact.name);

    if (compareResult < 0)
    {
        node->left = insertContactHelper(node->left, contact);
    }
    else if (compareResult > 0)
    {
        node->right = insertContactHelper(node->right, contact);
    }

    return node;
}

void insertContactDepthOrder(Contact contact)
{
    root = insertContactHelper(root, contact);
}

void inOrderTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("Name: %s, Phone: %s\n", node->contact.name, node->contact.phone);
        inOrderTraversal(node->right);
    }
}

void preOrderTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        printf("Name: %s, Phone: %s\n", node->contact.name, node->contact.phone);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

void postOrderTraversal(TreeNode *node)
{
    if (node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("Name: %s, Phone: %s\n", node->contact.name, node->contact.phone);
    }
}

void display(TreeNode *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%s", ptr->contact.name);
        display(ptr->left, level + 1);
    }
}

void displayMenu()
{
    printf("\nBinary Tree Operations (Contact Management)\n");
    printf("1. Create Binary Tree (Level Order)\n");
    printf("2. Create Binary Tree (Depth Order)\n");
    printf("3. In-Order Traversal\n");
    printf("4. Pre-Order Traversal\n");
    printf("5. Post-Order Traversal\n");
    printf("6. Display Binary Tree Structure\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

void createBinaryTreeLevelOrder()
{
    int numContacts;
    printf("Enter the number of contacts: ");
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; ++i)
    {
        Contact contact;
        printf("Enter name for contact %d: ", i + 1);
        scanf("%s", contact.name);
        printf("Enter phone for contact %d: ", i + 1);
        scanf("%s", contact.phone);

        insertContactLevelOrder(contact);
    }

    printf("Binary Tree created using level order traversal.\n");
}

void createBinaryTreeDepthOrder()
{
    int numContacts;
    printf("Enter the number of contacts: ");
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; ++i)
    {
        Contact contact;
        printf("Enter name for contact %d: ", i + 1);
        scanf("%s", contact.name);
        printf("Enter phone for contact %d: ", i + 1);
        scanf("%s", contact.phone);

        insertContactDepthOrder(contact);
    }

    printf("Binary Tree created using depth order traversal.\n");
}

int main()
{
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createBinaryTreeLevelOrder();
            break;
        case 2:
            createBinaryTreeDepthOrder();
            break;
        case 3:
            printf("In-Order Traversal:\n");
            inOrderTraversal(root);
            break;
        case 4:
            printf("Pre-Order Traversal:\n");
            preOrderTraversal(root);
            break;
        case 5:
            printf("Post-Order Traversal:\n");
            postOrderTraversal(root);
            break;
        case 6:
            printf("Binary Tree Structure:\n");
            display(root, 0);
            break;
        case 7:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}