07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add and remove are O(log n), as the heap is a balanced binary tree and the running times are based on the height of the tree, which will always be log(n).
2. All variable are properly deleted.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1: 7 will be added to the left node of 16, then swap with 16. Afterwards 3 will be added to the right node of the newly added 7, then will swap with 7, then swap with 6, then swap with 4 before sitting at the root.

10.2: 55 will be set as the root node, then will swap with 8 on the right, then will swap with 16 on the right of that node and then settle. After 8 is removed 93 will be set as the root and then swapped with 9 on the left, then swap with 17, then swap with 19 and settle.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
A d-ary tree will be almost identical to a binary tree, except that 2 will be replaced with d in the equations. i.e. parent will be (i-1)/d and children will be (di) + (1 to d).

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Think of this similarly to a binary search tree, and try to implement the functions similarly to that tree, i.e. with recursion.
