/*
Linked list header file
R. Guicherd - April 2020
*/

// Header guard
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
Includes
*/

#include <stdbool.h>

/*
Structure definition
*/

// Structure for Element
typedef struct Element Element;
struct Element{
	int number;
	Element* next;
};

// Structure for List
typedef struct List List;
struct List{
	int length;
	Element* first;
};

/*
Function prototypes
*/

// Initialize list
List* initializeList();

// Add element
void addElement(List* list, const int newNumber);

// Add element at
void addElementAt(List* list, const int pos, const int newNumber);

// Delete element
void deleteElement(List* list);

// Delete element at
void deleteElementAt(List* list, const int pos);

// Pop element
int popList(List* list);

// Min element
int minList(const List* list);

// Max element
int maxList(const List* list);

// Sum list
int sumList(const List* list);

// Product list
int productList(const List* list);

// Contains element
bool inList(const List* list, const int num);

// Sorted list
bool isSorted(const List* list);

// Element location
int locateList(const List* list, const int num);

// Return element at
Element* elementAt(const List* list, const int pos);

// Swap elements
void swapElement(List* list, const int pos1, const int pos2);

// Move element
void moveElement(List* list, const int posi, const int posf);

// Partition list
void partitionNumList(List* list, const int n);

// Reverse list
void reverseList(List* list);

// Bubble sort list
void bubbleSortList(List* list);

// Insertion sort list
void insertionSortList(List* list);

// Merge list
List* mergeList(const List* list1, const List* list2);

// Clone list
List* cloneList(const List* list);

// Display list
void displayList(const List* list);

// Size list
int sizeList(const List* list);

// Delete list
void deleteList(List* list);

#endif