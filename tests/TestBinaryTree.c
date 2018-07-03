#include<stdio.h>

#include "BinaryTree.h"

int main(void){

    struct BSTNode* rootNode = NULL;

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

    printf("Finding the height of the BST recursively... Should return 3...\n");
    printf("===> %d \n", findHeight(rootNode));

    puts("\n");

    puts("------------------------------");
    puts("SUCCESS: ALL TEST CASES PASSED");
    puts("------------------------------");

    return 0;
}