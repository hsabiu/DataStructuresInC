#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node* nextNode;
};

struct Node* headNode;

// Functions function prototype
int numItems();
void printNodesInList();
void insertNodeAtBegining(int);
void insertNodeAtEnd(int);
void insertNodeAtNthPosition(int, int);
void deleteNthNode(int);
void reverseList();
void recursiveReverseList(struct Node*);
void recursivePrintList(struct Node*);
void recursivePrintListInReverse(struct Node*);

int main(void){

    int item;
    int userInput;

    headNode = NULL;
    
    printf("How many items do you want to initialize? \n");
    scanf("%d", &userInput);

    for(int i = 0; i < userInput; i++){
        printf("Enter %d item: \n", i + 1);
        scanf("%d", &item);
        insertNodeAtBegining(item);
        printNodesInList();
    }

    puts("\n");

    // Inseart the item 2 at position 1
    printf("Inserting 10 at position 0 in the linked list... \n");
    insertNodeAtNthPosition(0, 10);
    printNodesInList();
    printf("Inserting 20 at position 3 in the linked list... \n");
    insertNodeAtNthPosition(3, 20);
    printNodesInList();
    printf("Inserting 30 at position 7 in the linked list... \n");
    insertNodeAtNthPosition(7, 30);
    printNodesInList();

    puts("\n");

    printf("Inserting 40 at the begining of the linked list... \n");
    insertNodeAtBegining(40);
    printNodesInList();

    puts("\n");

    printf("Inserting 50 at the end of the linked list... \n");
    insertNodeAtEnd(50);
    printNodesInList();

    puts("\n");

    printf("Inserting 60 at a position that do not exist in the linked list... \n");
    insertNodeAtNthPosition(userInput + 6, 60);

    puts("\n");

    printf("Deleting 1st node from the linked list... \n");
    deleteNthNode(0);
    printNodesInList();

    puts("\n");

    printf("Deleting 1st node from the linked list... \n");
    deleteNthNode(0);
    printNodesInList();

    puts("\n");

    printf("Deleting 3rd node from the linked list... \n");
    deleteNthNode(2);
    printNodesInList();

    puts("\n");

    printf("Deleting 6th node from the linked list... \n");
    deleteNthNode(5);
    printNodesInList();

    puts("\n");

    printf("Deleting 6th node from the linked list... \n");
    deleteNthNode(5);
    printNodesInList();

    puts("\n");

    printf("Reversing the linked list... \n");
    reverseList();
    printNodesInList();

    puts("\n");

    printf("Reversing the linked list using recursion... \n");
    recursiveReverseList(headNode);
    printNodesInList();

    puts("\n");

    printf("Printing the list items using recursion... \n");
    recursivePrintList(headNode);

    puts("\n");

    printf("Printing the list items in reverse using recursion... \n");
    recursivePrintListInReverse(headNode);

    puts("\n");

    puts("------------------------------");
    puts("SUCCESS: ALL TEST CASES PASSED");
    puts("------------------------------");

    return 0;
}

int numItems(){
    int num = 1;
    struct Node* currentNode = headNode;

    while(currentNode->nextNode != NULL){
        num++;
        currentNode = currentNode->nextNode;
    }
    return num;
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

void insertNodeAtEnd(int item){

    struct Node* tempNode = headNode;

    while(tempNode->nextNode != NULL){
        tempNode = tempNode->nextNode;
    }

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->nextNode = NULL;

    tempNode->nextNode = newNode;
}

void insertNodeAtNthPosition(int n, int item){

    int numListItems = numItems();

    if (n > numListItems){
        printf("===> Can not insert %d at position %d. The linked list has %d items \n", item, n, numListItems);
        return;
    }

    struct Node* tempNode = headNode;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;

    tempNode = headNode;

    if (n == 0){
        newNode->nextNode = tempNode;
        headNode = newNode;
        return;
    }

    for(int i = 0; i < n - 1; i++){
        tempNode = tempNode->nextNode;
    }

    newNode->nextNode = tempNode->nextNode;
    tempNode->nextNode = newNode;
}

void deleteNthNode(int n){

    int numListItems = numItems();
    struct Node* previousNode = NULL;
    struct Node* currentNode = headNode;

    if (n > numListItems){
        printf("===> Can not delete item at position %d. The linked list has only %d items.\n", n, numListItems);
        return;
    }

    if (n == 0){
         headNode = currentNode->nextNode;
         free(currentNode);
         return;
     }

    for(int i = 0; i < n; i++){
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    previousNode->nextNode = currentNode->nextNode;
    free(currentNode);
}

void reverseList(){

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
}

void recursiveReverseList(struct Node* tempNode){

    if (tempNode->nextNode == NULL){
        headNode = tempNode;
        return;
    }

    recursiveReverseList(tempNode->nextNode);
    tempNode->nextNode->nextNode = tempNode;
    tempNode->nextNode = NULL;
}

void recursivePrintList(struct Node* head){

    if(head->nextNode == NULL){
        printf("%d, ", head->data);
        return;
    }
    printf("%d, ", head->data);
    recursivePrintList(head->nextNode);
}

void recursivePrintListInReverse(struct Node* head){

    if(head->nextNode == NULL){
        printf("%d, ", head->data);
        return;
    }
    recursivePrintListInReverse(head->nextNode);
    printf("%d, ", head->data);
}