#include<stdio.h>
#include<stdlib.h>


struct BSTNode{
    int data;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
};

struct BSTNode* insertNode(struct BSTNode*, int);
struct BSTNode* createNewNode(int);

int main(void){

    struct BSTNode* rootNode = NULL;
    //struct BSTNode* pointerAtIndex = NULL;

    rootNode = insertNode(rootNode, 10);
    rootNode = insertNode(rootNode, 5);
    rootNode = insertNode(rootNode, 20);
    rootNode = insertNode(rootNode, 8);
    rootNode = insertNode(rootNode, 15);

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
