# Linked List

This repository contains a `C` library for single linked list. The list is composed of elements that contain an integer as well as a pointer to the next element. The structure `List` is composed of a pointer towards the first element of the list as well as a variable `length` storing the number of elements contained within the list. The last element of the list has a pointer equal to `NULL` in order to 

## Function Documentation

This section contains some explanations about the functions contained in the library `linkedlist`.

* `List* initializeList()`: Initializes a list with one element containing the integer 0.

* `void addElement(List* list, const int newNumber)`: Add a new element containing `newNumber`, in first position within the list.

* `void addElementAt(List* list, const int pos, const int newNumber)`: Add a new element containing `newNumber`, in position `pos` within the list. Where `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `void deleteElement(List* list)`: Delete the first element of the list.

* `void deleteElementAt(List* list, const int pos)`: Delete an element located at position `pos`, where, `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `int popList(List* list)`: Returns the value of the first element of the list and deletes it.

* `int minList(const List* list)`: Returns the minimum element number of the list.

* `int maxList(const List* list)`: Returns the maximum element number of the list.

* `int sumList(const List* list)`: Sums the element numbers of the list.

* `int productList(const List* list)`: Multiplies the element numbers of the list.

* `double averageList(const List* list)`: Returns the average value of the list.

* `bool inList(const List* list, const int num)`: Returns `true` if `num` is in the list, `false` otherwise.

* `bool isSorted(const List* list)`: Returns `true` if the list is sorted in ascending order, `false` otherwise.

* `int locateList(const List* list, const int num)`: Returns the first position index of `num` if in the list, or zero otherwise.

* `Element* elementAt(const List* list, const int pos)`: Returns an element pointer for the element located at the index `pos`.

* `void swapElement(List* list, const int pos1, const int pos2)`: Swap element located in `pos1` with element located in `pos2`.

* `void moveElement(List* list, const int posi, const int posf)`: Move element located at `posi` to a new position `posf`.

* `void partitionNumList(List* list, const int n)`: Partitions the list by placing the elements less than `n` at the beginning and the elements greater or equal to `n` at the end.

* `void reverseList(List* list)`: Reverse all the elements of the list.

* `void bubbleSortList(List* list)`: Sort the list in ascending order using the bubble sort algorithm.

* `void insertionSortList(List* list)`: Sort the list in ascending order using the insertion sort algorithm.

* `List* mergeList(const List* list1, const List* list2)`: Merges `list1` with `list2` into a single list object.

* `List* cloneList(const List* list)`: Clones the list provided as an input.

* `void displayList(const List* list)`: Display the elements of the list.

* `int sizeList(const List* list)`: Returns the list size contained in the variable `length`.

* `void deleteList(List* list)`: Delete the entire list.

## Compilation

The main file included is provided to test the different functions described above, it can be compiled by entering the following command in a terminal:

```gcc -o main_exe main.c linkedlist.c -I.```
