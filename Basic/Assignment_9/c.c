#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc function

// Definition of Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to get the height of a binary tree
int getHeight(struct Node* node) {
    // Base case: Empty tree
    if (node == NULL) {
        return 0;
    }

    // Recursively find heights of left and right subtrees
    int left_height = getHeight(node->left);
    int right_height = getHeight(node->right);

    // Return the maximum height of the two subtrees + 1 (root)
    return max(left_height, right_height) + 1;
}

// Function to construct a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to remove a node from the binary tree
struct Node* removeNode(struct Node* root, int key) {
    // Base case: If the tree is empty, return NULL
    if (root == NULL) {
        return root;
    }

    // Recursive call to remove the node from left or right subtree
    if (key < root->data) {
        root->left = removeNode(root->left, key);
    } else if (key > root->data) {
        root->right = removeNode(root->right, key);
    } else { // If the node with key is found
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = NULL;  // Initially, the tree is empty

    // Construct the binary tree from the given array
    // Here, we'll simply insert elements one by one into the binary search tree
    for (int i = 0; i < n; i++) {
        if (root == NULL) {
            root = newNode(arr[i]);
        } else {
            struct Node* current = root;
            struct Node* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (arr[i] < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (arr[i] < parent->data) {
                parent->left = newNode(arr[i]);
            } else {
                parent->right = newNode(arr[i]);
            }
        }
    }

    // Remove the node to be cut
    root = removeNode(root, k);

    // Get the height of the remaining tree
    int height = getHeight(root);
    printf("%d\n", height);

    return 0;
}
