#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include "Stack.h"

int main(void){

    int top = -1;

    puts("\n");

    printf("Creating an empty stack...\n");
    int* stack = createStack(MAXSIZE);

    puts("\n");

    printf("Testing if stack is empty... test should return 1...\n");
    printf("===> %d \n", stackIsEmpty(&top));

    puts("\n");

    printf("Pushing 1 onto the stack...\n");
    push(1, &top, stack, MAXSIZE);
    printElements(&top, stack);

    puts("\n");

    printf("Pushing 2 onto the stack...\n");
    push(2, &top, stack, MAXSIZE);
    printElements(&top, stack);

    puts("\n");

    printf("Pushing 3 onto the stack...\n");
    push(3, &top, stack, MAXSIZE);
    printElements(&top, stack);

    puts("\n");

    printf("Pushing 4 onto the stack...\n");
    push(4, &top, stack, MAXSIZE);
    printElements(&top, stack);

    puts("\n");

    printf("Pushing 5 onto the stack...\n");
    push(5, &top, stack, MAXSIZE);
    printElements(&top, stack);

    puts("\n");

    printf("Testing if stack is empty... test should return 0...\n");
    printf("===> %d \n", stackIsEmpty(&top));

    puts("\n");

    printf("Getting the peek value of stack...\n");
    printf("===> %d \n", peek(&top, stack));

    puts("\n");

    printf("Popping item from the stack...\n");
    printf("Pop returned: %d \n", pop(&top, stack));
    printElements(&top, stack);

    puts("\n");

    printf("Popping item from the stack...\n");
    printf("Pop returned: %d \n", pop(&top, stack));
    printElements(&top, stack);

    puts("\n");

    printf("Popping item from the stack...\n");
    printf("Pop returned: %d \n", pop(&top, stack));
    printElements(&top, stack);

    puts("\n");

    printf("Popping item from the stack...\n");
    printf("Pop returned: %d \n", pop(&top, stack));
    printElements(&top, stack);

    puts("\n");

    printf("Getting the peek value of stack... peek should now be 1...\n");
    printf("===> %d \n", peek(&top, stack));

    puts("\n");

    return 0;
}