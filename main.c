/*
Main file
R. Guicherd - April 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	
	// Pop list
	printf("Pop list returns: %d\n", popList(mylist));
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Add element at and display
	position = 3;
	addElementAt(mylist, position, 42);
	printf("Add element at position: %d\n", position);
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Add element at and display
	position = 7;
	addElementAt(mylist, position, 1);
	printf("Add element at position: %d\n", position);
	displayList(mylist);
	printf("List size: %d\n", sizeList(mylist));
	
	// Min element
	printf("Min element is: %d\n", minList(mylist));
	
	// Max element
	printf("Max element is: %d\n", maxList(mylist));
	
	// Sum list
	printf("Sum of list elements is: %d\n", sumList(mylist));
	
	// Product list
	printf("Product of list elements is: %d\n", productList(mylist));
	
	// Average list
	printf("Average list is: %f\n", averageList(mylist));
	
	// Check in list
	printf("Element 0 in list? %d\n", inList(mylist, 0));
	
	// Locate element
	printf("Locate element 1 in list: %d\n", locateList(mylist, 1));
	printf("Locate element 42 in list: %d\n", locateList(mylist, 42));
	
	// Element at
	Element* elt = elementAt(mylist, 1);
	printf("The first element is at %p contains %d and points to next element at %p\n", elt, elt->number, elt->next);
	
	// Swap element
	printf("Swap elements 1 and 3 in list\n");
	displayList(mylist);
	swapElement(mylist, 1, 3);
	displayList(mylist);
	
	// Move element
	printf("Move element 1 to 7 in list\n");
	moveElement(mylist, 1, 7);
	displayList(mylist);
	
	// Sort list with bubble sort
	printf("Sort list with bubble sort\n");
	clock_t begin = clock();
	bubbleSortList(mylist);
	clock_t end = clock();
	displayList(mylist);
	printf("Execution time: %lf\n", (double) (end - begin)/CLOCKS_PER_SEC);
	
	// Merge two lists
	List* mylist1 = initializeList();
	addElement(mylist1, 2);
	printf("Merging the two lists\n");
	displayList(mylist);
	displayList(mylist1);
	List* mylist2 = mergeList(mylist, mylist1);
	displayList(mylist2);
	printf("List 2 size: %d\n", sizeList(mylist2));
	
	// Partition num list
	printf("Partition list 2 with number 3\n");
	printf("Pivot value = %d\n", partitionNumList(mylist2, 3));
	displayList(mylist2);
	
	// Update element
	position = 2;
	int num = -1;
	printf("Update element in pos: %d by %d\n", position, num);
	updateElement(mylist2, position, num);
	displayList(mylist2);
	
	// Partition elt list
	position = 4;
	printf("Partition list 2 with element in position %d\n", position);
	addElement(mylist2, 3);
	addElement(mylist2, 3);
	displayList(mylist2);
	printf("Pivot value = %d\n", partitionEltList(mylist2, elementAt(mylist2, position)));
	displayList(mylist2);
	
	// Clone list
	List* clone = cloneList(mylist2);
	printf("The cloned list is: ");
	displayList(mylist2);
	
	// Check isSorted
	printf("Is list cloned sorted? %d\n", isSorted(clone));
	
	// Sort list with insertion sort
	printf("Sort list with insertion sort\n");
	begin = clock();
	insertionSortList(clone);
	end = clock();
	displayList(clone);
	printf("Execution time: %lf\n", (double) (end - begin)/CLOCKS_PER_SEC);
	
	// Check isSorted
	printf("Is list cloned sorted? %d\n", isSorted(clone));
	
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