*This project has been created as part of 42 curriculum by vlnikola*
# Description
push_swap is an algorithm project. The goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution for optimized data sorting.
## Rules
* You have 2 stacks named A and B.
* The goal is to sort the numbers in Stack A in ascending order.
* You start with Stack A containing a random amount of negative and/or positive numbers which cannot be duplicated.
* Stack B is empty.
## Operations
| Code  | Instruction                         | Action                                                             |
| ----- | ----------------------------------- | ------------------------------------------------------------------ |
| sa  | swap a                              | Swap the first 2 elements at the top of stack A.                   |
| sb  | swap b                              | Swap the first 2 elements at the top of stack B.                   |
| ss  | swap a + swap b                     | sa and sb at the same time.                                    |
| pa  | push a                              | Take the first element at the top of B and put it at the top of A. |
| pb  | push b                              | Take the first element at the top of A and put it at the top of B. |
| ra  | rotate a                            | Shift all elements of stack A up by 1.                             |
| rb  | rotate b                            | Shift all elements of stack B up by 1.                             |
| rr  | rotate a + rotate b                 | ra and rb at the same time.                                    |
| rra | reverse rotate a                    | Shift all elements of stack A down by 1.                           |
| rrb | reverse rotate b                    | Shift all elements of stack B down by 1.                           |
| rrr | reverse rotate a + reverse rotate b | rra and rrb at the same time.                                  |
## Algorithm
### Small Stacks (<= 5 numbers)
* 2 and 3 numbers: Hard-coded logic. 
	- **Example:**
		```bash
		if (fst > snd && snd < trd && fst < trd)
		sa(*stack_a);
		```
* 5 numbers: Push the smallest numbers to B, sort 3 numbers in A, and push the smallest numbers back to A
### Large Stacks (> 5 numbers)
I implemented a Quick Sort algorithm:
The algorithm splits the stack into smaller chunks until they are small enough to sort instantly.
1. Partitioning Stack A (qsort_a)
    - Find the median of the current range.
    - Push all numbers smaller than the median to Stack B.
	- Rotate all numbers higher than the median in Stack A.
    - Recursively sort the remaining numbers in A, then the numbers pushed to B.
2. Partitioning Stack B (qsort_b)
    - Find the median of the current range.
	- Push all numbers larger or equal to the median back to Stack A.
	- Rotate all numbers lower than the median in Stack A.
	- Recursively sort the numbers pushed to A, then the remaining numbers in B.
3. Recursion stops when a partition is tiny:
	- Size ≤ 2: Swap if needed (sa / sb).
	- Size = 3: Use a hardcode logic from previous part.
---
# Installation & Usage
## 1. Compilation
Use the Makefile to compile the project.
```bash
make
```
## 2. Running the Program
Pass a list of integers as arguments.
```bash
./push_swap 4 67 3 87 23
```
## 3. Error Handling
The program strictly validates input. It outputs Error followed by a new line to Standard Error (fd = 2) in case of:
- Non-integer arguments.
- Numbers greater than INT_MAX or less than INT_MIN.
- Duplicate numbers.
#### Example of error
```bash
./push_swap 1 2 one 3
Error
```
## 4. Testing
You can check the number of instructions using wc -l:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
To verify the stack is actually sorted, you can use the provided checker:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
OK
```
***
# Resources
[Linked Lists - GeeksForGeeks](https://www.geeksforgeeks.org/dsa/linked-list-data-structure/)
[Linked List implementation of stack](https://www.geeksforgeeks.org/c/stack-using-linked-list-in-c/)
[Sorting Algorithms - GeeksForGeeks](https://www.geeksforgeeks.org/dsa/sorting-algorithms/)
[push_swap tester by gemartin99](https://github.com/gemartin99/Push-Swap-Tester)
[push_swap visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)

## AI usage
This project utilized AI assistance for the following specific tasks:

- Brainstorm and visualize how to implement linked lists tailored to the push_swap stack operations.
- Debugging: 
	- The AI helped identify and fix a critical integer overflow bug in the get_median function (changing char to int) which was causing infinite loops on large datasets.
- Edge Cases:
	- I used AI to generate a list of tricky inputs (e.g., duplicates, INT_MAX, non-integer inputs) to verify the program's error management.
