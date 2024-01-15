#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[20];
    struct Contact *left;
    struct Contact *right;
};

struct Contact *createContact(char name[], char phone[])
{
    struct Contact *newNode = (struct Contact *)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Contact *insertContact(struct Contact *root, char name[], char phone[])
{
    if (root == NULL)
    {
        return createContact(name, phone);
    }

    int compareResult = strcmp(name, root->name);

    if (compareResult < 0)
    {
        root->left = insertContact(root->left, name, phone);
    }
    else if (compareResult > 0)
    {
        root->right = insertContact(root->right, name, phone);
    }

    return root;
}

void inorderTraversal(struct Contact *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Contact *root)
{
    if (root != NULL)
    {
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Contact *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
    }
}

int calculateHeight(struct Contact *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

void display(struct Contact *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        for (i = 0; i < level; i++)
            printf("    ");
        printf("%s", ptr->name);
        display(ptr->left, level + 1);
    }
}

struct Contact *findMin(struct Contact *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Contact *deleteContact(struct Contact *root, char name[])
{
    if (root == NULL)
    {
        return root;
    }

    int compareResult = strcmp(name, root->name);

    if (compareResult < 0)
    {
        root->left = deleteContact(root->left, name);
    }
    else if (compareResult > 0)
    {
        root->right = deleteContact(root->right, name);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Contact *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Contact *temp = root->left;
            free(root);
            return temp;
        }

        struct Contact *temp = findMin(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteContact(root->right, temp->name);
    }
    return root;
}

struct Contact *searchContact(struct Contact *root, char name[])
{
    if (root == NULL || strcmp(name, root->name) == 0)
    {
        return root;
    }

    if (strcmp(name, root->name) < 0)
    {
        return searchContact(root->left, name);
    }
    else
    {
        return searchContact(root->right, name);
    }
}

int main()
{
    struct Contact *root = NULL;
    int choice;
    char name[50], phone[20];
    struct Contact *result;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a contact\n");
        printf("2. Display Inorder Traversal\n");
        printf("3. Display Preorder Traversal\n");
        printf("4. Display Postorder Traversal\n");
        printf("5. Display Height of the BST\n");
        printf("6. Display BST Structure\n");
        printf("7. Delete a contact\n");
        printf("8. Search for a contact\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter the number of nodes: ");
            scanf("%d", &n);

            for (int i = 0; i < n; i++)
            {
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                root = insertContact(root, name, phone);
            }
        }
        break;

        case 2:
            printf("Inorder Traversal:\n");
            inorderTraversal(root);
            break;

        case 3:
            printf("Preorder Traversal:\n");
            preorderTraversal(root);
            break;

        case 4:
            printf("Postorder Traversal:\n");
            postorderTraversal(root);
            break;

        case 5:
            printf("Height of the BST: %d\n", calculateHeight(root));
            break;

        case 6:
            printf("BST Structure:\n");
            display(root, 0);
            break;

        case 7:
            printf("Enter name to delete: ");
            scanf("%s", name);
            root = deleteContact(root, name);
            break;

        case 8:
            printf("Enter name to search: ");
            scanf("%s", name);
            result = searchContact(root, name);
            if (result != NULL)
            {
                printf("Contact found: %s, %s\n", result->name, result->phone);
            }
            else
            {
                printf("Contact not found.\n");
            }
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
