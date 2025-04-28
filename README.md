Set Operations Program

Overview
This C++ program allows users to perform a variety of set operations on user-defined sets. The program accepts multiple sets and a universal set as input, then computes and displays:
-	Intersection of the sets
-	Union of the sets
-	Set Difference for each set relative to the intersection
-	Set Complement for each set relative to the universal set

The program uses dynamic memory allocation, vectors, and object-oriented programming concepts such as classes, constructors, destructors, and functions.

Features
Input a universal set and multiple named sets.
Calculate and display:
-	Intersection of all sets.
-	Union of all sets.
-	Difference between each set and the intersection.
-	Complement of each set relative to the universal set.
-	Dynamic memory management for flexibility.
-	Clean and organized output formatting.



Technologies
C++
Standard Template Library (STL) - vector, string
Dynamic memory (new and delete)

How It Works:
1.	User inputs the number of elements in the universal set and its elements.

2.	User defines how many sets they want to create and provides names and elements for each set.

3.	Program processes and displays:

-	All sets and the universal set.
-	Their intersection.
-	Their union.
-	The set difference for each set.
-	The set complement for each set.

Project Structure
Set.h and Set.cpp:
Contains the Set class, which handles all set operations.

setOperations.cpp (main.cpp):

Handles user input and controls the flow of the program.

Example
[ENTER] the number of elements in the Universe: 5
[ENTER] all the 5 elements in the Universal set:
1 2 3 4 5
How many sets do you want to create: 2
What will this set be called: A
[ENTER] the number of elements in set A:
{ 2 }
[ENTER] all the 2 elements in set A:
{ 1 2 }
What will this set be called: B
[ENTER] the number of elements in set B:
{ 2 }
[ENTER] all the 2 elements in set B:
{ 2 3 }

...

The intersection of the sets is:
{ 2 }

The union of the sets is:
{ 1 2 3 }

A - Intersection:
{ 1 }
B - Intersection:
{ 3 }

Complement of A:
{ 3 4 5 }
Complement of B:
{ 1 4 5 }

How to Run
Clone the repository:
git clone https://github.com/your-username/SetOperations.git
Open the project in your C++ IDE (such as Visual Studio Code).

Compile and run:

g++ main.cpp -o SetOperations
./SetOperations
Notes
Ensure you properly deallocate any dynamically allocated memory to avoid memory leaks (handled in the destructor).

Input validation (e.g., preventing duplicates) can be improved in future versions.

Author
Daniel H. Kombe
C++ programmer | Explorer of algorithms and data structures

