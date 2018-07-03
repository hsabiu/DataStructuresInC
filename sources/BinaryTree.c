#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "BinaryTree.h"

struct BSTNode{
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
};


struct BSTNode* createNewNode(int item){
    struct BSTNode* newNode = (struct BSTNode*) malloc(sizeof(struct BSTNode));
    newNode->data = item;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct BSTNode* insertNode(struct BSTNode* rootNode, int item){

    if (rootNode == NULL){
        struct BSTNode* newNode = createNewNode(item);
        rootNode = newNode;
    }
    else if(item <= rootNode->data){
        rootNode->leftChild = insertNode(rootNode->leftChild, item);
    }
    else{
        rootNode->rightChild = insertNode(rootNode->rightChild, item);
    }

    return rootNode;
}

bool searchNode(struct BSTNode* rootNode, int item){

    if (rootNode == NULL) return false;
    else if (item == rootNode->data) return true;
    else if (item <= rootNode->data) return searchNode(rootNode->leftChild, item);
    else return searchNode(rootNode->rightChild, item);
}

int findMin(struct BSTNode* rootNode){
    if(rootNode == NULL){
        printf("ERROR: Empty is tree");
        return -1;
    }

    while(rootNode->leftChild != NULL){
        rootNode = rootNode->leftChild;
    }
    return rootNode->data;
}

int findMax(struct BSTNode* rootNode){
    if(rootNode == NULL){
        printf("ERROR: Empty is tree");
        return -1;
    }

    while(rootNode->rightChild != NULL){
        rootNode = rootNode->rightChild;
    }
    return rootNode->data;
}

int findMinRecursive(struct BSTNode* rootNode){
    if(rootNode == NULL){
        printf("ERROR: Empty tree");
        return -1;
    }

    else if(rootNode->leftChild == NULL){
        return rootNode->data;
    }
    
    else{
        return findMinRecursive(rootNode->leftChild);
    }
}

int findMaxRecursive(struct BSTNode* rootNode){
    if(rootNode == NULL){
        printf("ERROR: Empty tree");
        return -1;
    }

    else if(rootNode->rightChild == NULL){
        return rootNode->data;
    }
    
    else{
        return findMaxRecursive(rootNode->rightChild);
    }
}

int findHeight(struct BSTNode* rootNode){

    if(rootNode == NULL){
        return 0;
    }

    int leftHeight = findHeight(rootNode->leftChild);
    int rightHeight = findHeight(rootNode->rightChild);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else{
        return rightHeight + 1;
    }
}

void BSTPreOrderTraversal(struct BSTNode* root){
    if(root == NULL) return;

    printf("%d, ", root->data);
    BSTPreOrderTraversal(root->leftChild);
    BSTPreOrderTraversal(root->rightChild);
}

void BSTInOrderTraversal(struct BSTNode* root){
    if(root == NULL) return;

    BSTInOrderTraversal(root->leftChild);
    printf("%d, ", root->data);
    BSTInOrderTraversal(root->rightChild);
}

void BSTPostOrderTraversal(struct BSTNode* root){
    if(root == NULL) return;

    BSTPostOrderTraversal(root->leftChild);
    BSTPostOrderTraversal(root->rightChild);
    printf("%d, ", root->data);
}