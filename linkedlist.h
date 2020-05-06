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
void addElement(List* list, int newNumber);

// Add element at
void addElementAt(List* list, int pos, int newNumber);

// Delete element
void deleteElement(List* list);

// Delete element at
void deleteElementAt(List* list, int pos);

// Pop element
int popList(List* list);

// Min element
int minList(List* list);

// Max element
int maxList(List* list);

// Contains element
bool inList(List* list, int num);

// Element location
int locateList(List* list, int num);

// Reverse list
void reverseList(List* list);

// Display list
void displayList(List* list);

// Size list
int sizeList(List* list);

// Delete list
void deleteList(List* list);

#endif