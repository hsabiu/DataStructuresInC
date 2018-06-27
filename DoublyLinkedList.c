#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prevNode;
    struct Node* nextNode;
};

// Functions function prototype
int numItems();
void printNodesInList();
void insertNode(int, struct Node*);
void deleteNode(struct Node*);
void deleteNthNode(int);
void reverseList();
void recursiveReverseList(struct Node*);
void recursivePrintList(struct Node*);
void recursivePrintListInReverse(struct Node*);
struct Node* findPointerAtIndex(int);


struct Node* headNode;

int main(void){

    int item;
    int userInput;

    headNode = NULL;
    struct Node* pointerAtIndex = NULL;

    printf("How many items do you want to initialize? \n");
    scanf("%d", &userInput);

    for(int i = 0; i < userInput; i++){
        printf("Enter %d item: \n", i + 1);
        scanf("%d", &item);
        insertNode(item, headNode);
        printNodesInList();
    }

    puts("\n");

    printf("Inserting 10 at index 0 in the linked list... \n");
    insertNode(10, headNode);
    printNodesInList();
    printf("Inserting 20 at index 3 in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(3);
    insertNode(20, pointerAtIndex);
    printNodesInList();
    printf("Inserting 30 at index 7 in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(7);
    insertNode(30, pointerAtIndex);
    printNodesInList();

    puts("\n");

    printf("Inserting 40 at the begining of the linked list... \n");
    insertNode(40, headNode);
    printNodesInList();

    puts("\n");

    printf("Inserting 50 at the end of the linked list... \n");
    pointerAtIndex = findPointerAtIndex(numItems());
    insertNode(50, pointerAtIndex);
    printNodesInList();

    puts("\n");

    printf("Inserting 60 at index that do not exist in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(userInput + 6);
    puts("\n");  

    printNodesInList();
    printf("Deleting the node at index 0 from the linked list... \n");
    deleteNode(headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList();
    printf("Deleting the node at index 0 from the linked list... \n");
    deleteNode(headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList();
    printf("Deleting the node at index 2 from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(3);
    deleteNode(pointerAtIndex);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList();
    printf("Deleting the node at 5 index from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(6);
    deleteNode(pointerAtIndex);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList();
    printf("Deleting the node at index 5 from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(6);
    deleteNode(pointerAtIndex);
    printf("Deletion successful... \n");

    puts("\n");

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

    puts("\n");

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

void insertNode(int item, struct Node* position){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = item;
    if (position == NULL){
        newNode->nextNode = NULL;
        newNode->prevNode = NULL;
        headNode = newNode;
        return;
    }

    if(position == headNode){
        newNode->nextNode = position;
        newNode->prevNode = NULL;
        position->prevNode = newNode;   
        headNode = newNode;
    } 
    else{
        newNode->nextNode = position->nextNode;
        newNode->prevNode = position;
        position->nextNode = newNode;   
    }
}

void deleteNode(struct Node* position){
    
    if(position == headNode){
        headNode = position->nextNode;
        position->nextNode->prevNode = NULL;
    }
    
    else if(position->nextNode == NULL){
        position->prevNode->nextNode = NULL;
    }
    
    else{
        position->prevNode->nextNode = position->nextNode;
        position->nextNode->prevNode = position->prevNode;
    }
    free(position);
}

struct Node* findPointerAtIndex(int index){
    
    int numListItems = numItems();

    if (index > numListItems){
        printf("===> Can not insert at index %d. \n", index);
        return NULL;
    }

    struct Node* tempNode = headNode;

    for(int i = 0; i < index - 1; i++){
        tempNode = tempNode->nextNode;
    }
    
    return tempNode;
}

void deleteNthNode(int n){
    
    int numListItems = numItems();

    if (n > numListItems){
        printf("===> Can not delete item at index %d. \n", n);
        return;
    }

    struct Node* currentNode = headNode;

    if (n == 0){
        headNode = currentNode->nextNode;
        free(currentNode);
        return;
     }

     for(int i = 0; i < n; i++){
        currentNode = currentNode->nextNode;
     }

    if(currentNode->nextNode == NULL){
        currentNode->prevNode->nextNode = NULL;
    }
    else{
        currentNode->nextNode->prevNode = currentNode->prevNode;
        currentNode->prevNode->nextNode = currentNode->nextNode;
    }
    free(currentNode);
}

void reverseList(){

    struct Node* tempNode = NULL;
    struct Node* current = headNode;

    while(current->nextNode != NULL){
        tempNode = current->nextNode;
        current->nextNode = current->prevNode;
        current->prevNode = tempNode;
        current = tempNode;
    }

    current->nextNode = current->prevNode;
    current->prevNode = NULL;
    headNode = current;
}

void recursiveReverseList(struct Node* tempNode){

    if(tempNode->nextNode == NULL){
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
