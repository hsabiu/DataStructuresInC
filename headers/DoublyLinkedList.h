#ifndef DOUBLYLINKEDLIST_H_
#define DOUBLYLINKEDLIST_H_

struct Node* insertNode(int, struct Node*, struct Node*);
struct Node* deleteNode(struct Node*, struct Node*);
struct Node* reverseList(struct Node*);
struct Node* recursiveReverseList(struct Node*);
struct Node* findPointerAtIndex(int, struct Node*);

int numItems(struct Node*);
void recursivePrintList(struct Node*);
void recursivePrintListInReverse(struct Node*);
void printNodesInList(struct Node*);

#endif /* DOUBLYLINKEDLIST_H_ */