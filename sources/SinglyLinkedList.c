#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* nextNode;
};

int numItems(struct Node* headNode){

    int num = 1;

    while(headNode->nextNode != NULL){
        num++;
        headNode = headNode->nextNode;
    }
    return num;
}

void printNodesInList(struct Node* headNode){

    printf("List items: ");

    while(headNode != NULL){
        printf("%d, ", headNode->data);
        headNode = headNode->nextNode;
    }

    printf("\n");
}

struct Node* insertNode(int item, struct Node* position, struct Node* headNode){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;

    if (position == NULL){
        newNode->nextNode = NULL;
        headNode = newNode;
        return headNode;
    }

    if(position == headNode){
        newNode->nextNode = position;
        headNode = newNode;
    } 
    else{
        newNode->nextNode = position->nextNode;
        position->nextNode = newNode;   
    }

    return headNode;

}

struct Node* deleteNode(struct Node* position, struct Node* headNode){

    struct Node* nodeToDelete = position->nextNode;
    
    if(position == headNode){
        headNode = position->nextNode;
    }
    
    else if(nodeToDelete->nextNode == NULL){
        position->nextNode = NULL;
    }
    
    else{
        position->nextNode = nodeToDelete->nextNode;
        free(nodeToDelete);
    }

    return headNode;
}

struct Node* findPointerAtIndex(int index, struct Node* headNode){
    
    int numListItems = numItems(headNode);

    if (index > numListItems){
        printf("===> Can not insert at index %d. \n", index);
        return NULL;
    }

    for(int i = 0; i < index - 1; i++){
        headNode = headNode->nextNode;
    }
    
    return headNode;
}

struct Node* reverseList(struct Node* headNode){

    struct Node *current, *next, *prev;
    current = headNode;
    prev = NULL;

    while(current != NULL){
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }

    headNode = prev;
    return headNode;
}

struct Node* recursiveReverseList(struct Node* headNode){

    if (headNode->nextNode == NULL){
        return headNode;
    }

    struct Node* newHead = recursiveReverseList(headNode->nextNode);
    headNode->nextNode->nextNode = headNode;
    headNode->nextNode = NULL;

    return newHead;
}

void recursivePrintList(struct Node* headNode){

    if(headNode->nextNode == NULL){
        printf("%d, ", headNode->data);
        return;
    }
    printf("%d, ", headNode->data);
    recursivePrintList(headNode->nextNode);
}

void recursivePrintListInReverse(struct Node* headNode){

    if(headNode->nextNode == NULL){
        printf("%d, ", headNode->data);
        return;
    }
    recursivePrintListInReverse(headNode->nextNode);
    printf("%d, ", headNode->data);
}