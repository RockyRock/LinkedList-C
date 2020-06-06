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
void addElement(List* list, const int newNumber){
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

void addElementAt(List* list, const int pos, const int newNumber){
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
void deleteElementAt(List* list, const int pos){
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
int minList(const List* list){
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
int maxList(const List* list){
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

// Sum list
int sumList(const List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization
	Element* current = list->first;
	int sum = 0;
	
	// Loop through the list elements
	while (current != NULL){
		// Add element to sum
		sum += current->number;
		// Move to next element
		current = current->next;
	}
	
	return sum;
}

// Product list
int productList(const List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization
	Element* current = list->first;
	int product = 1;
	
	// Loop through the list elements
	while (current != NULL){
		// Multiply element to product
		if (current->number == 0){
			return 0;
		}
		else{
			product *= current->number;
		}
		// Move to next element
		current = current->next;
	}
	
	return product;
}

// Element in list
bool inList(const List* list, const int num){
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

// Sorted list
bool isSorted(const List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize current at first element
	Element* current = list->first;
	
	while (current->next != NULL){
		if (current->number > current->next->number){
			return false;
		}
		// Move to next element
		current = current->next;
	}
	
	return true;
}

// Element location
int locateList(const List* list, const int num){
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
Element* elementAt(const List* list, const int pos){
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
void swapElement(List* list, const int pos1, const int pos2){
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

// Move element
void moveElement(List* list, const int posi, const int posf){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on position integers
	if (posi > list->length || posi < 1 || posf > list->length || posf < 1){
		exit(EXIT_FAILURE);
	}
	else if (posi == posf){
		return;
	}
	
	// Element current, elt and prev
	Element* current = list->first;
	Element* elt = NULL;
	Element* prev = NULL;
	int pos = 1;
	
	// Check for posi at first element
	if (posi == 1){
		elt = list->first;
	}
	
	// Find prev and elt in list
	while (pos < posi){
		// Store previous and element
		if (pos == posi - 1){
			prev = current;
			elt = current->next;
		}
		// Move to next element
		current = current->next;
		pos++;
	}
	
	// Set next of prev to next of elt
	if (prev != NULL){
		prev->next = elt->next;
	}
	else{
		list->first = elt->next;
	}
	
	// Reinsert element at posf
	current = list->first;
	pos = 1;
	if (posf == 1){
		elt->next = list->first;
		list->first = elt;
	}
	while (pos < posf){
		if (pos == posf - 1){
			elt->next = current->next;
			current->next = elt;
		}
		// Move to next element
		current = current->next;
		pos++;
	}
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

// Sort list
void bubbleSortList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize current, flag and idx
	Element* current = list->first;
	bool flag = true;
	int idx = 1;
	
	while (flag){
		// Reset current, flag and idx at start of each loop
		current = list->first;
		flag = false;
		idx = 1;
		// Loop through list and swap elements
		while (current->next != NULL){
			if (current->number > current->next->number){
				// If next element smaller swap, pointer will also move ahead
				swapElement(list, idx, idx + 1);
				// Set flag to true and increment idx
				flag = true;
				idx++;
			}
			else{
				// Move to next element without swap
				current = current->next;
				idx++;
			}
		}	
	}
}

// Insertion sort list
void insertionSortList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize current, idx and pos
	Element* current = list->first;
	Element* elt = list->first;
	int idx = 1;
	int pos = 1;
	
	// Loop throught list
	while (current->next != NULL){
		// Insert element at the begining if not in right place
		if (current->number > current->next->number){
			elt = list->first;
			pos = 1;
			while (elt->number <= current->next->number){
				// Move to next to find insertion position
				elt = elt->next;
				pos++;
			}
			// Increment idx and move element from idx to pos
			idx++;
			moveElement(list, idx, pos);
		}
		else{
			// Move to next element
			current = current->next;
			idx++;
		}
	}
}

// Merge list
List* mergeList(const List* list1, const List* list2){
	// Check on list1
	if (list1 == NULL || list1->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on list2
	if (list2 == NULL || list2->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize new list
	List* list = initializeList();
	
	// Copy list1 in list
	Element* current1 = list1->first;
	while (current1 != NULL){
		// Add new element in list
		if (current1 == list1->first){
			list->first->number = current1->number;
		}
		else{
			addElementAt(list, list->length + 1, current1->number);
		}
		// Move to next element
		current1 = current1->next;
	}
	
	// Add list2 in list
	Element* current2 = list2->first;
	while (current2 != NULL){
		// Add element in list
		addElementAt(list, list->length + 1, current2->number);
		// Move to next element
		current2 = current2->next;
	}
	
	return list;
}

// Clone list
List* cloneList(const List* list){
	// Check on list1
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize clone and first element
	List* clone = initializeList();
	Element* current = list->first;
	
	// Loop through elements to clone
	while (current != NULL){
		// Copy element to clone and check for first
		if (current == list->first){
			clone->first->number = current->number;
		}
		else{
			addElementAt(clone, clone->length + 1, current->number);
		}
		// Move to next element
		current = current->next;
	}
	
	return clone;
}

// Display list function
void displayList(const List* list){
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
int sizeList(const List* list){
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