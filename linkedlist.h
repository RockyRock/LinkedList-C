/*
Linked list header file
R. Guicherd - April 2020
*/

// Function prototypes

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

// Display list
void displayList(List* list);

// Size list
int sizeList(List* list);

// Delete list
void deleteList(List* list);