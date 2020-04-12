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
	Element* next;
	
	// Delete all elements of the list
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	
	// Free list
	free(list);
}