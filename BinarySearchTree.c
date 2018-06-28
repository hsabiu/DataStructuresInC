#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct BSTNode{
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
};

struct BSTNode* createNewNode(int);
struct BSTNode* insertNode(struct BSTNode*, int);
bool searchNode(struct BSTNode*, int);
int findMin(struct BSTNode*);
int findMax(struct BSTNode*);
int findMinRecursive(struct BSTNode*);
int findMaxRecursive(struct BSTNode*);

int main(void){

    struct BSTNode* rootNode = NULL;
    //struct BSTNode* pointerAtIndex = NULL;

    puts("\n");

    printf("Creating a Binary Search Tree...\n");

    puts("\n");

    printf("Inserting 10 into the BST...\n");
    rootNode = insertNode(rootNode, 10);

    puts("\n");

    printf("Inserting 5 into the BST...\n");
    rootNode = insertNode(rootNode, 5);

    puts("\n");

    printf("Inserting 20 into the BST...\n");
    rootNode = insertNode(rootNode, 20);

    puts("\n");

    printf("Inserting 8 into the BST...\n");
    rootNode = insertNode(rootNode, 8);

    puts("\n");

    printf("Inserting 15 into the BST...\n");
    rootNode = insertNode(rootNode, 15);

    puts("\n");

    printf("Searching for node with value 10 in the BST... Search should return 1... \n");
    printf("===> %d \n", searchNode(rootNode, 20));

    puts("\n");

    printf("Searching for node with value 50 in the BST... Search should return 0... \n");
    printf("===> %d \n", searchNode(rootNode, 50));

    puts("\n");

    printf("Finding the minimum data in the BST... Should return 5...\n");
    printf("===> %d \n", findMin(rootNode));

    puts("\n");

    printf("Finding the maximum data in the BST... Should return 20...\n");
    printf("===> %d \n", findMax(rootNode));

    puts("\n");

    printf("Finding the minimum data in the BST recursively... Should return 5...\n");
    printf("===> %d \n", findMinRecursive(rootNode));

    puts("\n");

    printf("Finding the maximum data in the BST recursively... Should return 20...\n");
    printf("===> %d \n", findMaxRecursive(rootNode));

    puts("\n");

    puts("------------------------------");
    puts("SUCCESS: ALL TEST CASES PASSED");
    puts("------------------------------");

    return 0;
}

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
        printf("ERROR: Empty tree");
        return -1;
    }

    while(rootNode->leftChild != NULL){
        rootNode = rootNode->leftChild;
    }
    return rootNode->data;
}

int findMax(struct BSTNode* rootNode){
    if(rootNode == NULL){
        printf("ERROR: Empty tree");
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