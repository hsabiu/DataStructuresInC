#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool stackIsEmpty(int* top){
    if(*top == -1) return true;
    else return false;
}

int* createStack(int size){

    int* stack = (int*) calloc(size, sizeof(int));
    return stack;

}

void push(int data, int* top, int* stack, int size){

    if(*top == size - 1){
        stack = (int*) realloc(stack, size * 2);
    }

    stack[++(*top)] = data;
}

int pop(int* top, int* stack){

    if (stackIsEmpty(top)){
        printf("ERROR: Can not pop from an empty stack.\n");
        return -1;
    }

    return stack[(*top)--];
}

int peek(int* top, int* stack){
    return stack[*top];
}

void printElements(int* top, int* stack){
    printf("===>  ");
    for(int i = 0; i <= *top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}