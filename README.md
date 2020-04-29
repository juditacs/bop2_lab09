# Task 1 (mandatory)

`IComparable` and `ISerializable` are abstract interface classes, `Person` is derived from them both (multiple interface inheritance).

Implement the missing functions in `Person.h` and `Person.cpp`. You may need to declare new functions as well.

Decomposition of the program:
- IComparable.h, ISerializable.h, Person.h: class declaration headers;
- Person.cpp: implementation of class members declared in the header;
- Main.cpp: the main program with testing code.

# Task 2 (mandatory)

`Sorter.h` declares a `Sorter` class that is a collection of multiple sorting algorithms. Each sorting algorithm takes an array of `IComparable*` pointers. These functions can sort any type that implements the `IComparable` interface such as our `Person` type.

Add a `Sorter.cpp` file and implement bubble sort and quicksort there. Test your solution in `Main.cpp`.

# Task 3 (optional)

There are many other sorting alorigthms. Add another one and **test it** in the main function. Examples: merge sort (in place or not), insertion sort.

# Task 4 (optional)

Add another _sortable_ type. Implementing the `IComparable` interface makes a type _sortable_. Create an array of your type and sort it via the `Sorter` class. Test your solution in the main function.

Examples of sortable types:

1. Complex numbers. Should be sorted by absolute value (length of the vector).
2. Rational numbers as a ratio of two integers p/q. Numerical sorting is well defined.
3. 3D vectors. Should be sorted by length.

Completing one or both optional tasks can make up for mistakes in the first task.