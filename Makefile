CC = gcc
CFLAGS += -Wall

tree: BinaryTree.o TestBinaryTree.o objects
	$(CC) $(CFLAGS) objects/BinaryTree.o objects/TestBinaryTree.o -o objects/TestBinaryTree
	objects/TestBinaryTree

objects:
	mkdir $@

BinaryTree.o: sources/BinaryTree.c objects
	$(CC) $(CFLAGS) -c -Iheaders sources/BinaryTree.c -o objects/BinaryTree.o 

TestBinaryTree.o: tests/TestBinaryTree.c objects
	$(CC) $(CFLAGS) -c -Iheaders tests/TestBinaryTree.c -o objects/TestBinaryTree.o 

clean:
	rm objects/*.o objects/TestBinaryTree