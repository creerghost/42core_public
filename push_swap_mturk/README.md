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
I implemented [Mechanical turk algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0), where the focus is on keeping stack A sorted at all times by inserting elements from stack B into their correct positions.
1.  **Push to B:** Push all elements from stack A to stack B until only 3 elements remain in A.
2.  **Sort three:** Sort the 3 remaining elements in stack A using a simple hard-coded logic.
3.  **Return one-by-one:**
    * Iterate through every node in stack B.
    * Find the *Target node* in stack A for stack B:
		- The node in stack A smaller than the current node in stack B,
		- The node is the smallest in stack A.
    * Calculate the *Cost* (number of rotations) to bring both the B-node and its target node to the top.
    * Identify the *Cheapest node* (lowest combined cost).
    * Execute the move using optimized double rotations (*rr* or *rrr* where possible).
    * Push the node back to A.
4.  **Final rotations:** Rotate stack A until the smallest number is at the top.
```c
typedef struct s_stack
{
	int		content;
	int		index; // index of element in the stack
	int		cost_a; // number of operations to rotate the target node to the top
	int		cost_b; // number of operations to rotate the element to the top
	int		is_above_median; // decides the position of element in the stack
	struct s_stack	*target_node; // element of stack B points to the element of stack A
	struct s_stack	*next;
}			t_stack
```
>Note
 This algorithm can also be used for 4 and 5 numbers (it is not exceeding 13 operations), but since I already had the 5 number algorithm (from previous tries), I decided to keep it in my project.
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
[push_swap Turk algorithm by Yutong Deng](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)
[push_swap Turk algorithm by A.Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## AI usage
This project utilized AI assistance for the following specific tasks:

- Bring some ideas with implementation of cost calculation
- How can I determine when I execute double or single rotations
- Making a table in README to reduce the manual work
- Generate a list of tricky inputs (e.g., duplicates, INT_MAX, non-integer inputs) to verify the program's error management.
- Making a bash script (test_random.sh) to test the program.
