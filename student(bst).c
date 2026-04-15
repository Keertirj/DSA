#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Create new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// Search
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum value node
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Inorder Traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main Menu
int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert\n2. Search\n3.Display \n4.Exit \n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 3:
                printf("BST (Inorder): ");
                inorder(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
