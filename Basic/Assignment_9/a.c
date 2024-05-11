#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the binary tree
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the maximum between two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum path sum in a binary tree
int maxPathSum(struct TreeNode* root, int* result) {
    // Base case
    if (root == NULL)
        return 0;
    
    // Recursive calls for left and right subtrees
    int leftSum = maxPathSum(root->left, result);
    int rightSum = maxPathSum(root->right, result);
    
    // Calculating the maximum path sum ending at the current node
    int maxSingle = max(max(leftSum, rightSum) + root->value, root->value);
    
    // Calculating the maximum path sum including the current node
    int maxTop = max(maxSingle, leftSum + rightSum + root->value);
    
    // Updating the result if the maximum path sum found so far
    *result = max(*result, maxTop);
    
    // Returning the maximum path sum ending at the current node
    return maxSingle;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Array to store the weights of Peanut Butter jars
    int peanutButterWeights[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &peanutButterWeights[i]);
    }
    
    // Building the binary tree using the input array
    struct TreeNode* nodes[n];
    for (int i = 0; i < n; ++i) {
        if (peanutButterWeights[i] != -1) {
            nodes[i] = createNode(peanutButterWeights[i]);
        } else {
            nodes[i] = NULL;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nodes[i] != NULL) {
            if (2*i+1 < n && nodes[2*i+1] != NULL) {
                nodes[i]->left = nodes[2*i+1];
            }
            if (2*i+2 < n && nodes[2*i+2] != NULL) {
                nodes[i]->right = nodes[2*i+2];
            }
        }
    }
    
    int result = 0;
    maxPathSum(nodes[0], &result);
    printf("%d\n", result);
    
    return 0;
}
