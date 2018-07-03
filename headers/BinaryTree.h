#include<stdbool.h>

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

struct BSTNode* createNewNode(int);
struct BSTNode* insertNode(struct BSTNode*, int);

void BSTPreOrderTraversal(struct BSTNode*);
void BSTInOrderTraversal(struct BSTNode*);
void BSTPostOrderTraversal(struct BSTNode*);

int findMin(struct BSTNode*);
int findMax(struct BSTNode*);
int findMinRecursive(struct BSTNode*);
int findMaxRecursive(struct BSTNode*);
int findHeight(struct BSTNode*);

bool searchNode(struct BSTNode*, int);

#endif /* BINARYTREE_H_ */
