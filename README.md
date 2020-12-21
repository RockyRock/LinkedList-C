# Linked List

This repository contains a `C` library for single linked list. The list is composed of elements that contain an integer as well as a pointer to the next element. The structure `List` is composed of a pointer towards the first element of the list as well as a variable `length` storing the number of elements contained within the list. The last element of the list has a pointer equal to `NULL` in order to 

## Function Documentation

This section contains some explanations about the functions contained in the library `linkedlist`.

* `List* initializeList()`: Initialize a list with one element containing the integer 0.

* `void addElement(List* list, const int num)`: Add a new element containing `num`, in first position within the list.

* `void addElementAt(List* list, const int pos, const int num)`: Add a new element containing `num`, in position `pos` within the list. Where `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `void deleteElement(List* list)`: Delete the first element of the list.

* `void deleteElementAt(List* list, const int pos)`: Delete an element located at position `pos`, where, `pos = 1` and `pos = length` respectively represent the first and last elements of the list.

* `void updateElement(List* list, const int pos, const int num)`: Update the number of the element located at the position index `pos`, with the number `num`.

* `int popList(List* list)`: Return the value of the first element of the list and deletes it.

* `int minList(const List* list)`: Return the minimum element number of the list.

* `int maxList(const List* list)`: Return the maximum element number of the list.

* `int sumList(const List* list)`: Sum the element numbers of the list.

* `int productList(const List* list)`: Multiply the element numbers of the list.

* `double averageList(const List* list)`: Return the average value of element numbers of the list.

* `bool inList(const List* list, const int num)`: Return `true` if `num` is in the list, `false` otherwise.

* `bool isSorted(const List* list)`: Return `true` if the list is sorted in ascending order, `false` otherwise.

* `int locateList(const List* list, const int num)`: Return the first position index of `num` if in the list, or zero otherwise.

* `Element* elementAt(const List* list, const int pos)`: Return an element pointer for the element located at the index `pos`.

* `void swapElement(List* list, const int pos1, const int pos2)`: Swap element located in `pos1` with element located in `pos2`.

* `void moveElement(List* list, const int posi, const int posf)`: Move element located at `posi` to a new position `posf`.

* `int partitionNumList(List* list, const int num)`: Partition the list by placing the elements less than `num` at the beginning and the elements greater or equal to `num` at the end, the position index of the last element strictly less than `num` is returned.

* `int* partitionEltList(List* list, Element* elt)`: Partition the list by placing the elements strictly less than `elt` number at the beginning and the elements strictly greater towards the end. The position indices of the right element equal to `elt` number, the pivot element `elt` and the left element equal to `elt` number are returned as an integer array. Corresponding indices are set to zero if `elt` does not belong to `list` or if no elements are equal to `elt` number.

* `int* partitionEltSublist(List* list, Element* elt, const int posi, const int posf)`: Partition the sublist obtained from `list` between the position index `posi` and `posf` included, by placing the elements strictly less than `elt` number at the beginning and the elements strictly greater towards the end. The position indices of the right element equal to `elt` number, the pivot element `elt` and the left element equal to `elt` number are returned as an integer array. Corresponding indices are set to zero if `elt` does not belong to `list` or if no elements are equal to `elt` number. 

* `void frontBackSplitList(List* list, List* front, List* back)`: Split the list into a front and a back list, in case the initial list has an odd number of elements the front list gets one more element than the back list. The function argument `list` as well as the argument `front` both point to the front list.

* `void reverseList(List* list)`: Reverse all the elements of the list.

* `void shuffleList(List* list)`: Shuffle all the elements of the list.

* `void bubbleSortList(List* list)`: Sort the list in ascending order using the bubble sort algorithm.

* `void insertionSortList(List* list)`: Sort the list in ascending order using the insertion sort algorithm.

* `void quickSortSublist(List* list, const int lo, const int hi)`: Sort the sublist obtained from `list` between `lo` and `hi` in ascending order using the quick sort algorithm.

* `void quickSortList(List* list)`: Sort the list in ascending order using the quick sort algorithm.

* `void mergeSortList(List* list)`: Sort the list in ascending order using the merge sort algorithm.

* `List* mergeList(const List* list1, const List* list2)`: Merge `list1` with `list2` into a single new list object.

* `List* mergeSortedList(List* list1, List* list2)`: Merge two sorted lists in ascending order into one sorted list also in ascending order.

* `List* cloneList(const List* list)`: Clone the list provided as an input.

* `void displayList(const List* list)`: Display the elements of the list.

* `int sizeList(const List* list)`: Return the list size contained in the variable `length`.

* `void deleteList(List* list)`: Delete the entire list.

## Compilation

The main file included is provided to test the different functions described above, it can be compiled by entering the following command in a terminal:

```gcc -o main_exe main.c linkedlist.c -I.```

Alternatively, a `Makefile` is available in the repository and can be used based on the following commands:

- `make`: compiles the source code in object files, and link them into an executable file called `main_exe`.
- `make clean`: cleans the object files and the executable file.
