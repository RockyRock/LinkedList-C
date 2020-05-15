/*
Linked list source file
R. Guicherd - April 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// List initialization function
List* initializeList(){
	List* list = malloc(sizeof(*list));
	Element* element = malloc(sizeof(*element));
	
	if (list == NULL || element == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize list parameter
	element->number = 0;
	element->next = NULL;
	list->length = 1;
	list->first = element;
	
	return list;
}

// Add element function
void addElement(List* list, int newNumber){
	// Creation of new element
	Element *new = malloc(sizeof(*new));
	if (list == NULL || list->first == NULL || new == NULL){
		exit(EXIT_FAILURE);
	}
	// Set new element number
	new->number = newNumber;
	
	// Insertion new element
	new->next = list->first;
	list->first = new;
	
	// Increment list size
	list->length++;
}

void addElementAt(List* list, int pos, int newNumber){
	// Creation of new element
	Element *new = malloc(sizeof(*new));
	if (list == NULL || new == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check position range
	if (pos > list->length + 1 || pos < 1){
		exit(EXIT_FAILURE);
	}
	
	// Set new element number
	new->number = newNumber;
	
	// Insert element at index pos
	if (pos == 1){
		addElement(list, newNumber);
	}
	else{
		// Loop find element before index pos
		int i = 1;
		Element* current = list->first;
		while (i < pos - 1){
			current = current->next;
			i++;
		}
		// Insert new element after current
		new->next = current->next;
		current->next = new;
		// Increment list size
		list->length++;
	}
}

// Delete element function
void deleteElement(List* list){
	// Check on list
	if (list == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on list first element
	if (list->first != NULL){
		Element* toDelete = list->first;
		list->first = list->first->next;
		list->length--;
		free(toDelete);
	}
}

// Delete element at function
void deleteElementAt(List* list, int pos){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check position range
	if (pos > list->length || pos <= 0){
		exit(EXIT_FAILURE);
	}
	
	// Delete element at index pos
	if (pos == 1){
		deleteElement(list);
	}
	else{
		// Loop find element before index pos
		int i = 1;
		Element* current = list->first;
		while (i < pos - 1){
			current = current->next;
			i++;
		}
		// Delete new element after current
		Element* toDelete = current->next;
		current->next = current->next->next;
		free(toDelete);
		// Decrement list size
		list->length--;
	}
}

// Pop element
int popList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Get first element number of the list
	int number = list->first->number;
	
	// Delete first element
	deleteElement(list);
	
	return number;
}

// Returns min element
int minList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Store first element as min incumbent
	Element* current = list->first;
	int min = current->number;
	
	// Loop through all list elements
	while (current != NULL){
		// Replace incumbent if lesser
		if (min > current->number){
			min = current->number;
		}
		// Move to next element
		current = current->next;
	}
	
	return min;
}

// Returns max element
int maxList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Store first element as max incumbent
	Element* current = list->first;
	int max = current->number;
	
	// Loop through all list elements
	while (current != NULL){
		// Replace incumbent if greater
		if (max < current->number){
			max = current->number;
		}
		// Move to next element
		current = current->next;
	}
	
	return max;
}

// Element in list
bool inList(List* list, int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize current at first element
	Element* current = list->first;
	
	while (current != NULL){
		if (current->number == num){
			return true;
		}
		// Move to next element
		current = current->next;
	}
	
	return false;
}

// Element location
int locateList(List* list, int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialise position index and first element
	int pos = 1;
	Element* current = list->first;
	
	// Loop through all list elements
	while (current != NULL){
		if (current->number == num){
			return pos;
		}
		// Move to next element
		current = current->next;
		pos++;
	}
	
	return 0;
}

// Return element at
Element* elementAt(List* list, int pos){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on position integer
	if (pos > list->length || pos < 1){
		exit(EXIT_FAILURE);
	}
	
	// Initialise element and index
	Element* elt = list->first;
	int i = 1;
	
	// Loop to find elt at index pos
	while (i < pos){
		elt = elt->next;
		i++;
	}
	
	return elt;
}

// Swap elements
void swapElement(List* list, int pos1, int pos2){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on position integers
	if (pos1 > list->length || pos1 < 1 || pos2 > list->length || pos2 < 1){
		exit(EXIT_FAILURE);
	}
	else if (pos1 == pos2){
		return;
	}
	
	// Element current, elt and prev elements
	Element* current = list->first;
	Element* elt1 = NULL;
	Element* elt2 = NULL;
	Element* prev1 = NULL;
	Element* prev2 = NULL;
	int pos = 1;
	
	// Check for pos1 at first element
	if (pos1 == 1){
		elt1 = list->first;
	}

	// Check for pos2 at first element
	if (pos2 == 1){
		elt2 = list->first;
	}
	
	// Find elts in the list
	while (pos < pos1 || pos < pos2){
		// Check on pos1
		if (pos == pos1 - 1){
			prev1 = current;
			elt1 = current->next;
		}
		// Check on pos2
		if (pos == pos2 - 1){
			prev2 = current;
			elt2 = current->next;
		}
		// Move to next element
		current = current->next;
		pos++;
	}
	
	// Check for first element with prev pointer
	if (prev1 != NULL){
		prev1->next = elt2;
	}
	else{
		list->first = elt2;
	}
	if (prev2 != NULL){
		prev2->next = elt1;
	}
	else{
		list->first = elt1;
	}
	
	// Swap the pointers to next
	Element* temp = elt2->next;
	elt2->next = elt1->next;
	elt1->next = temp;
}

// Reverse list order
void reverseList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization
	Element* previous = NULL;
	Element* current = NULL;
	Element* next = NULL;
	if (list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Set current to first list element
	current = list->first;
	
	// Loop through all list elements
	while (current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	
	// List change first element
	list->first = previous;
}

// Display list function
void displayList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Select first element as current
	Element* current = list->first;
	
	// Loop over the list and display
	while (current != NULL){
		printf("%d -> ", current->number);
		current = current->next;
	}
	// Print new line
	printf("NULL\n");
}

// Size list function
int sizeList(List* list){
	// Check on list
	if (list == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Return list size
	return list->length;
}

// Delete list
void deleteList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Select first element
	Element* current = list->first;
	Element* next = NULL;
	
	// Delete all elements of the list
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	
	// Free list
	free(list);
}