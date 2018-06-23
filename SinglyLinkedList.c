#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* nextNode;
};

struct Node* headNode;

void printNodesInList();
void insertNodeAtBegining(int);
void insertNodeAtEnd(int);
void insertNodeAtNthPosition(int, int);

int main(void){

    int userInput, item;
    headNode = NULL;
    
    printf("How many items do you want to initially insert? \n");
    scanf("%d", &userInput);

    for(int i = 0; i < userInput; i++){
        printf("Enter %d item: \n", i + 1);
        scanf("%d", &item);
        insertNodeAtBegining(item);
        printNodesInList();
    }

    // Inseart the item 2 at position 1
    printf("Inserting 10 at position 0 in the linked list... \n");
    insertNodeAtNthPosition(0, 10);
    printNodesInList();
    printf("Inserting 20 at position 3 in the linked list... \n");
    insertNodeAtNthPosition(3, 20);
    printNodesInList();
    // printf("Inserting 30 at position 7 in the linked list... \n");
    // insertNodeAtNthPosition(7, 30);
    // printNodesInList();

    // printf("Inserting 40 at the end of the linked list... \n");
    // insertNodeAtEnd(40);
    // printNodesInList();

    // insertNodeAtNthPosition(1, 50);
    // printNodesInList();

    return 0;
}

void printNodesInList(){

    struct Node* tempHeadNode = headNode;

    printf("List items: ");

    while(tempHeadNode != NULL){
        printf("%d, ", tempHeadNode->data);
        tempHeadNode = tempHeadNode->nextNode;
    }

    printf("\n");
}

void insertNodeAtBegining(int item){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;

    if(headNode != NULL){
        newNode->nextNode = headNode;
    }

    headNode = newNode;
}

void insertNodeAtNthPosition(int n, int item){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;

    struct Node* tempNode = headNode;

    if (n == 0){
        tempNode->nextNode = headNode;
        headNode = tempNode;
        return;
    }

    for(int i = 0; i < n - 1; i++){
        tempNode = tempNode->nextNode;
    }

    newNode->nextNode = tempNode->nextNode;
    tempNode->nextNode = newNode;
}

void insertNodeAtEnd(int item){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;

    struct Node* tempNode = headNode;

    while(tempNode->nextNode != NULL){
        tempNode = tempNode->nextNode;
    }

    newNode->nextNode = NULL;
    tempNode->nextNode = newNode;
}
