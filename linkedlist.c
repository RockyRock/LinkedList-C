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
	if (list == NULL || new == NULL){
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
	if (pos > list->length + 1 || pos <= 0){
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
	if (list == NULL){
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
	
	// Get first element of the list
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

// Reverse list order
void reverseList(List* list){
	// Check on list
	if (list == NULL){
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
	if (list == NULL){
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
	if (list == NULL){
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