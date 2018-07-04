#include<stdbool.h>

#ifndef STACK_H_
#define STACK_H_

#define MAXSIZE 101

bool stackIsEmpty(int*);

int pop(int*, int*);
int peek(int*, int*);
int* createStack(int);
void printElements(int*, int*);
void push(int, int*, int*, int);

#endif /* STACK_H_ */