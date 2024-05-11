#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Function to check if tree2 is a subtree of tree1
bool isSubtree(struct TreeNode* tree1, struct TreeNode* tree2) {
    if (tree2 == NULL)
        return true;
    if (tree1 == NULL)
        return false;
    
    // If current nodes match, check subtrees
    if (tree1->value == tree2->value && isSubtree(tree1->left, tree2->left) && isSubtree(tree1->right, tree2->right))
        return true;
    
    // Try subtree on left and right
    return isSubtree(tree1->left, tree2) || isSubtree(tree1->right, tree2);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Array to store the nodes of the community tree
    int communityTree[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &communityTree[i]);
    }
    
    // Array to store the nodes of the tree in hand
    int treeInHand[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &treeInHand[i]);
    }
    
    // Building the community tree using the input array
    struct TreeNode* communityNodes[n];
    for (int i = 0; i < n; ++i) {
        if (communityTree[i] != -1) {
            communityNodes[i] = createNode(communityTree[i]);
        } else {
            communityNodes[i] = NULL;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (communityNodes[i] != NULL) {
            if (2*i+1 < n && communityNodes[2*i+1] != NULL) {
                communityNodes[i]->left = communityNodes[2*i+1];
            }
            if (2*i+2 < n && communityNodes[2*i+2] != NULL) {
                communityNodes[i]->right = communityNodes[2*i+2];
            }
        }
    }
    
    // Building the tree in hand using the input array
    struct TreeNode* treeInHandNode = NULL;
    for (int i = 0; i < m; ++i) {
        if (treeInHand[i] != -1) {
            treeInHandNode = createNode(treeInHand[i]);
            break;
        }
    }
    if (treeInHandNode != NULL) {
        for (int i = 0; i < m; ++i) {
            if (2*i+1 < m && treeInHand[2*i+1] != -1) {
                treeInHandNode->left = createNode(treeInHand[2*i+1]);
            }
            if (2*i+2 < m && treeInHand[2*i+2] != -1) {
                treeInHandNode->right = createNode(treeInHand[2*i+2]);
            }
        }
    }
    
    // Check if the tree in hand is a subtree of the community tree
    if (isSubtree(communityNodes[0], treeInHandNode)) {
        printf("WIN\n");
    } else {
        printf("LOSS\n");
    }
    
    return 0;
}
