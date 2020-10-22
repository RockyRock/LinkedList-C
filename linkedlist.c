/*
Linked list source file
R. Guicherd - April 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// List initialization
List* initializeList(){
	// Memory allocation
	List* list = malloc(sizeof(*list));
	Element* element = malloc(sizeof(*element));
	
	// Check on list and first element
	if (list == NULL || element == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize list parameter
	element->number = 0;
	element->next = NULL;
	list->length = 1;
	list->first = element;
	
	// Return list
	return list;
}

// Add element
void addElement(List* list, const int num){
	// Creation of new element
	Element *new = malloc(sizeof(*new));
	// Check on list and first element
	if (list == NULL || list->first == NULL || new == NULL){
		exit(EXIT_FAILURE);
	}
	// Set new element number
	new->number = num;
	
	// Insertion new element
	new->next = list->first;
	list->first = new;
	
	// Increment list size
	list->length++;
}

// Add element at
void addElementAt(List* list, const int pos, const int num){
	// Creation of new element
	Element *new = malloc(sizeof(*new));
	if (list == NULL || new == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check position range
	if (pos < 1 || pos > list->length + 1){
		exit(EXIT_FAILURE);
	}
	
	// Set new element number
	new->number = num;
	
	// Insert element at index pos
	if (pos == 1){
		addElement(list, num);
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

// Delete element
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

// Delete element at
void deleteElementAt(List* list, const int pos){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check position range
	if (pos < 1 || pos > list->length){
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

// Update element
void updateElement(List* list, const int pos, const int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check position range
	if (pos < 1 || pos > list->length){
		exit(EXIT_FAILURE);
	}
	
	// Initialization idx and current
	int idx = 0;
	Element* current = list->first;
	
	// Loop through list element
	while (idx < pos -1){
		current = current->next;
		idx++;
	}
	
	// Update the element number at pos
	current->number = num;
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
	
	// Return element number
	return number;
}

// Min element
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
	
	// Return min value
	return min;
}

// Max element
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
	
	// Return max value
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
	
	// Return sum
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
			// Return zero
			return 0;
		}
		else{
			product *= current->number;
		}
		// Move to next element
		current = current->next;
	}
	
	// Return list product
	return product;
}

// Average list
double averageList(const List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization current and average
	Element* current = list->first;
	double average = 0;
	
	// Loop through the list elements
	while (current != NULL){
		// Add element divided by list length
		average += current->number/(double) list->length;
		// Move to next element
		current = current->next;
	}
	
	// Return list average
	return average;
}

// Contains element
bool inList(const List* list, const int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize current at first element
	Element* current = list->first;
	while (current != NULL){
		if (current->number == num){
			// Return true
			return true;
		}
		// Move to next element
		current = current->next;
	}
	
	// Return false
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
			// Return false
			return false;
		}
		// Move to next element
		current = current->next;
	}
	
	// Return true
	return true;
}

// Element location
int locateList(const List* list, const int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialize position index and first element
	int pos = 1;
	Element* current = list->first;
	
	// Loop through all list elements
	while (current != NULL){
		if (current->number == num){
			// Return position
			return pos;
		}
		// Move to next element
		current = current->next;
		pos++;
	}
	
	// Return zero
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
	
	// Initialize element and index
	Element* elt = list->first;
	int i = 1;
	
	// Loop to find elt at index pos
	while (i < pos){
		elt = elt->next;
		i++;
	}
	
	// Return element
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

// Partition list around number
int partitionNumList(List* list, const int num){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization elements
	int pivot = 0;
	Element* current = list->first;
	Element* prev = NULL;
	Element* low = NULL;
	
	// Loop throught list elements
	while (current != NULL){
		if (current->number < num){
			if (low == prev){
				// Update prev element
				prev = current;
			}
			else{
				// Move current element to the low side
				prev->next = current->next;
				if (low == NULL){
					// Case low NULL
					current->next = list->first;
					list->first = current;
				}
				else{
					// Insert current after low element
					current->next = low->next;
					low->next = current;
				}
			}
			// Update low element and increment pivot
			low = current;
			pivot++;
		}
		else{
			// Update prev element
			prev = current;
		}
		// Move current element to next of prev
		current = prev->next;
	}
	
	// Return pivot position
	return pivot;
}

// Partition list around element
int* partitionEltList(List* list, Element* elt){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on elt
	if (elt == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization elements
	bool first = true;
	bool flag = true;
	int* index = calloc(3,sizeof(int));
	Element* current = list->first;
	Element* prev = NULL;
	Element* low = NULL;
	Element* eql = NULL;
	
	// Loop throught list elements
	while (current != NULL){
		// Low side check
		if (current->number < elt->number){
			if (low == prev){
				// Update prev element
				prev = current;
			}
			else{
				// Move current element to the low side
				prev->next = current->next;
				if (low == NULL){
					// Case low NULL
					current->next = list->first;
					list->first = current;
				}
				else{
					// Insert current after low element
					current->next = low->next;
					low->next = current;
				}
			}
			// Update low element and increment index array
			low = current;
			index[0]++;
			index[1]++;
			index[2]++;
		}
		// Equal side check
		else if (current->number == elt->number){
			if (eql == prev){
				// Update prev element
				prev = current;
			}
			else{
				// Move current element to the eql side
				prev->next = current->next;
				if (eql == NULL && low == NULL){
					// Case eql and low NULL
					current->next = list->first;
					list->first = current;
				}
				else{
					// Case eql NULL
					if (eql == NULL){
						eql = low;
					}
					// Insert current after eql element
					current->next = eql->next;
					eql->next = current;
				}
			}
			// Update eql element and increment index array
			eql = current;
			if (first){
				index[0]++;
				first = false;
			}
			if (flag){
				index[1]++;
				if (current == elt){
					flag = false;
				}
			}
			index[2]++;
		}
		else{
			// Update prev element
			prev = current;
		}
		// Move current element to next of prev
		current = prev->next;
	}
	
	// Check if a first or elt were found
	if (first){
		index[0] = 0;
		index[1] = 0;
	}
	else if (flag){
		index[1] = 0;
	}
	
	// Return array of index
	return index;
}

// Partition sublist around element between posi and posf
int* partitionEltSublist(List* list, Element* elt, const int posi, const int posf){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check on position integers
	if (posi > list->length || posi < 1 || posf > list->length || posf < 1 || posi > posf){
		exit(EXIT_FAILURE);
	}
	
	// Check on elt
	if (elt == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Initialization elements
	bool first = true;
	bool flag = true;
	int* index = calloc(3,sizeof(int));
	int pos = 1;
	Element* current = list->first;
	Element* low = NULL;
	Element* eql = NULL;
	Element* prev = NULL;
	Element* last = NULL;
	
	// Set current to element at posi
	while (pos < posi){
		low = current;
		prev = current;
		current = current->next;
		pos++;
	}
	
	// Set last to element at posf
	last = current;
	while (pos <= posf){
		last = last->next;
		pos++;
	}
	
	// Loop throught list elements
	while (current != last){
		// Low side check
		if (current->number < elt->number){
			if (low == prev){
				// Update prev element
				prev = current;
			}
			else{
				// Move current element to the low side
				prev->next = current->next;
				if (low == NULL){
					// Case low NULL
					current->next = list->first;
					list->first = current;
				}
				else{
					// Insert current after low element
					current->next = low->next;
					low->next = current;
				}
			}
			// Update low element and increment index array
			low = current;
			index[0]++;
			index[1]++;
			index[2]++;
		}
		// Equal side check
		else if (current->number == elt->number){
			// Move current element to the eql side
			if (eql == NULL && low == NULL){
				// Case eql and low NULL
				if (prev == NULL){
					// Update prev element
					prev = current;
				}
				else{
					// Insert at list first
					prev->next = current->next;
					current->next = list->first;
					list->first = current;
				}
			}
			else{
				// Case eql NULL
				if (eql == NULL){
					eql = low;
				}
				// Check if eql is same as prev
				if (eql == prev){
					// Update prev element
					prev = current;
				}
				else{
					// Insert current after eql element
					prev->next = current->next;
					current->next = eql->next;
					eql->next = current;
				}
			}
			// Update eql element and increment index array
			eql = current;
			if (first){
				index[0]++;
				first = false;
			}
			if (flag){
				index[1]++;
				if (current == elt){
					flag = false;
				}
			}
			index[2]++;
		}
		else{
			// Update prev element
			prev = current;
		}
		// Move current element to next of prev
		current = prev->next;
	}

	// Shift indices by posi - 1
	index[0] += posi - 1;
	index[1] += posi - 1;
	index[2] += posi - 1;

	// Check if first or elt were found
	if (first){
		index[0] = 0;
		index[1] = 0;
	}
	else if (flag){
		index[1] = 0;
	}
	
	// Return array of index
	return index;
}

// Front-back split list
void frontBackSplitList(List* list, List* front, List* back){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Check list size
	if (list->length <= 1){
		return;
	}
	
	// Set front list to list
	front->first = list->first;
	front->length = (list->length + 1)/2;
	
	// Initialize current element
	Element* current = list->first;
	
	// Loop through half the list
	for(int i = 1; i < (list->length + 1)/2; i++){
		current = current->next;
	}
	
	// Set back list
	back->first = current->next;
	back->length = (list->length)/2;
	
	// Sever front-back link
	current->next = NULL;
	
	// Adjust initial list size
	list->length = front->length;
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

// Shuffle list
void shuffleList(List* list){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Loop through list and shuffle elements
	for(int i = 1; i < list->length + 1; i++){
		moveElement(list, i, 1 + rand() % (list->length));
	}
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


// Quick sort sublist
void quickSortSublist(List* list, const int lo, const int hi){
	// Check on list
	if (list == NULL || list->first == NULL){
		exit(EXIT_FAILURE);
	}
	
	// Partition list
	if (lo < hi){
		// Select middle pivot
		int pivot = (lo+hi)/2;
		// Partition sublist
		int* idx = partitionEltSublist(list, elementAt(list, pivot), lo, hi);
		// Iterate left side
		quickSortSublist(list, lo, idx[0] - 1);
		// Iterate right side
		quickSortSublist(list, idx[2] + 1, hi);
		// Free idx
		free(idx);
	}
}

// Quick sort list
void quickSortList(List* list){
	// Quick sort for the entire list
	quickSortSublist(list, 1, list->length);
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
	
	// Return merged list
	return list;
}

// Clone list
List* cloneList(const List* list){
	// Check on list
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
	
	// Return cloned list
	return clone;
}

// Display list
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
	// Print NULL and new line
	printf("NULL\n");
}

// Size list
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