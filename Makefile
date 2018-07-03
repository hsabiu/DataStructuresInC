CC = gcc
CFLAGS += -Wall



tree: BinaryTree.o TestBinaryTree.o objects
	$(CC) $(CFLAGS) objects/BinaryTree.o objects/TestBinaryTree.o -o objects/TestBinaryTree
	objects/TestBinaryTree

BinaryTree.o: sources/BinaryTree.c objects
	$(CC) $(CFLAGS) -c -Iheaders sources/BinaryTree.c -o objects/BinaryTree.o

TestBinaryTree.o: tests/TestBinaryTree.c objects
	$(CC) $(CFLAGS) -c -Iheaders tests/TestBinaryTree.c -o objects/TestBinaryTree.o
	

slinkedlist: SinglyLinkedList.o TestSinglyLinkedList.o objects
	$(CC) $(CFLAGS) objects/SinglyLinkedList.o objects/TestSinglyLinkedList.o -o objects/TestSinglyLinkedList
	objects/TestSinglyLinkedList

SinglyLinkedList.o: sources/SinglyLinkedList.c objects
	$(CC) $(CFLAGS) -c -Iheaders sources/SinglyLinkedList.c -o objects/SinglyLinkedList.o

TestSinglyLinkedList.o: tests/TestSinglyLinkedList.c objects
	$(CC) $(CFLAGS) -c -Iheaders tests/TestSinglyLinkedList.c -o objects/TestSinglyLinkedList.o


dlinkedlist: DoublyLinkedList.o TestDoublyLinkedList.o objects
	$(CC) $(CFLAGS) objects/DoublyLinkedList.o objects/TestDoublyLinkedList.o -o objects/TestDoublyLinkedList
	objects/TestDoublyLinkedList

DoublyLinkedList.o: sources/DoublyLinkedList.c objects
	$(CC) $(CFLAGS) -c -Iheaders sources/DoublyLinkedList.c -o objects/DoublyLinkedList.o

TestDoublyLinkedList.o: tests/TestDoublyLinkedList.c objects
	$(CC) $(CFLAGS) -c -Iheaders tests/TestDoublyLinkedList.c -o objects/TestDoublyLinkedList.o
	


objects:
	mkdir $@

clean:
	rm objects/*