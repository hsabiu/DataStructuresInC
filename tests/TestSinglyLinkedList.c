#include <stdio.h>
#include <stdlib.h>

#include "SinglyLinkedList.h"


int main(void){

    int item;
    int userInput;

    struct Node* headNode = NULL;
    struct Node* pointerAtIndex = NULL;

    printf("How many items do you want to initialize? \n");
    scanf("%d", &userInput);

    for(int i = 0; i < userInput; i++){
        printf("Enter %d item: \n", i + 1);
        scanf("%d", &item);
        headNode = insertNode(item, headNode, headNode);
        printNodesInList(headNode);
    }

    puts("\n");

    printf("Inserting 10 at index 0 in the linked list... \n");
    headNode = insertNode(10, headNode, headNode);
    printNodesInList(headNode);
    printf("Inserting 20 at index 3 in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(3, headNode);
    headNode = insertNode(20, pointerAtIndex, headNode);
    printNodesInList(headNode);
    printf("Inserting 30 at index 7 in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(7, headNode);
    headNode = insertNode(30, pointerAtIndex, headNode);
    printNodesInList(headNode);

    puts("\n");

    printf("Inserting 40 at the begining of the linked list... \n");
    headNode = insertNode(40, headNode, headNode);
    printNodesInList(headNode);

    puts("\n");

    printf("Inserting 50 at the end of the linked list... \n");
    pointerAtIndex = findPointerAtIndex(numItems(headNode), headNode);
    headNode = insertNode(50, pointerAtIndex, headNode);
    printNodesInList(headNode);

    puts("\n");

    printf("Inserting 60 at index that do not exist in the linked list... \n");
    pointerAtIndex = findPointerAtIndex(userInput + 6, headNode);
    puts("\n");  

    printNodesInList(headNode);
    printf("Deleting the node at index 0 from the linked list... \n");
    headNode = deleteNode(headNode, headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList(headNode);
    printf("Deleting the node at index 0 from the linked list... \n");
    headNode = deleteNode(headNode, headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList(headNode);
    printf("Deleting the node at index 2 from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(2, headNode);
    headNode = deleteNode(pointerAtIndex, headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList(headNode);
    printf("Deleting the node at index 5 from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(5, headNode);
    headNode = deleteNode(pointerAtIndex, headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList(headNode);
    printf("Deleting the node at index 5 from the linked list... \n");
    pointerAtIndex = findPointerAtIndex(5, headNode);
    headNode = deleteNode(pointerAtIndex, headNode);
    printf("Deletion successful... \n");

    puts("\n");

    printNodesInList(headNode);

    puts("\n");

    printf("Reversing the linked list... \n");
    headNode = reverseList(headNode);
    printNodesInList(headNode);

    puts("\n");

    printf("Reversing the linked list using recursion... \n");
    headNode = recursiveReverseList(headNode);
    printNodesInList(headNode);

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
