#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

struct Node* findPointerAtIndex(int, struct Node*);
struct Node* insertNode(int, struct Node*, struct Node*);
struct Node* deleteNode(struct Node*, struct Node*);
struct Node* reverseList(struct Node*);
struct Node* recursiveReverseList(struct Node*);

int numItems(struct Node*);
void printNodesInList(struct Node*);
void recursivePrintList(struct Node*);
void recursivePrintListInReverse(struct Node*);

#endif /* SINGLYLINKEDLIST_H_ */