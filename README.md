# Linked List

This repository contains a `C` library for single linked list. The list is composed of elements that contain an integer as well as a pointer to the next element. The structure `List` is composed of a pointer towards the first element of the list as well as a variable `length` storing the number of elements contained within the list. The last element of the list has a pointer equal to `NULL` in order to 

## Function Documentation

This section contains some explanations about the functions contained in the library `linkedlist`.

* `List* initializeList()`: Initializes a list with one element containing the integer 0.

* `void addElement(List* list, int newNumber)`: Add a new element containing `newNumber`, in first position within the list.

* `void addElementAt(List* list, int pos, int newNumber)`: Add a new element containing `newNumber`, in position `pos` within the list. Where `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `void deleteElement(List* list)`: Delete the first element of the list.

* `void deleteElementAt(List* list, int pos)`: Delete an element located at position `pos`, where, `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `int popList(List* list)`: Returns the value of the first element of the list and deletes it.

* `int minList(List* list)`: Returns the minimum element number of the list.

* `int maxList(List* list)`: Returns the maximum element number of the list.

* `bool inList(List* list, int num)`: Returns `true` if `num` is in the list, `false` otherwise.

* `int locateList(List* list, int num)`: Returns the first position index of `num` if in the list, or zero otherwise.

* `void swapElement(List* list, int pos1, int pos2)`: Swap element located in `pos1` with element located in `pos2`.

* `void reverseList(List* list)`: Reverse all the elements of the list.

* `void displayList(List* list)`: Display the elements of the list.

* `int sizeList(List* list)`: Returns the list size contained in the variable `length`.

* `void deleteList(List* list)`: Deleted the entire list.

