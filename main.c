/*
Main file
R. Guicherd - April 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[]){
	printf("****************\n");
	printf("Linked list test\n");
	printf("****************\n");
	
	// Initialize mylist and display
	int position = 0;
	List* mylist = initializeList();
	printf("List pointer at creation %p\n", &mylist);
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Add elements to mylist and display
	addElement(mylist, 1);
	printf("Add element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	addElement(mylist, 2);
	printf("Add element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	addElement(mylist, 3);
	printf("Add element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	addElement(mylist, 4);
	printf("Add element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	addElement(mylist, 5);
	printf("Add element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Reverse list
	reverseList(mylist);
	printf("Reverse list\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Add element at and display
	position = 3;
	addElementAt(mylist, position, 42);
	printf("Add element at position: %d\n", position);
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Delete element at and display
	position = 4;
	deleteElementAt(mylist, position);
	printf("Delete element at position: %d\n", position);
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Delete an element in mylist and display
	deleteElement(mylist);
	printf("Delete element\n");
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Delete mylist
	deleteList(mylist);
	printf("*** Delete mylist ***\n");
	
	return 0;
}