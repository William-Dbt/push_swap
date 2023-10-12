# 🖱 42Paris Project | push_swap

## Objectives

The goal of this project is to sort a list of random numbers which cannot be duplicated.  
This numbers will be present in two stacks (A and B) where B is empty at the start of the program.  
To helps us sort the numbers, we can only do the following operations:
- **sa** (swap a): Swap the first 2 elements at the top of stack a.  
	Do nothing if there is only one or no elements.  
- **sb** (swap b): Swap the first 2 elements at the top of stack b.  
	Do nothing if there is only one or no elements.  
- **ss** : sa and sb at the same time.  
- **pa** (push a): Take the first element at the top of b and put it at the top of a.  
	Do nothing if b is empty.  
- **pb** (push b): Take the first element at the top of a and put it at the top of b.  
	Do nothing if a is empty.  
- **ra** (rotate a): Shift up all elements of stack a by 1.  
	The first element becomes the last one.  
- **rb** (rotate b): Shift up all elements of stack b by 1.  
	The first element becomes the last one.  
- **rr** : ra and rb at the same time.  
- **rra** (reverse rotate a): Shift down all elements of stack a by 1.  
	The last element becomes the first one.  
- **rrb** (reverse rotate b): Shift down all elements of stack b by 1.  
	The last element becomes the first one.  
- **rrr** : rra and rrb at the same time.  

## Usage

`make` to compile the program.  
`clean` to clean objects files.  
`fclean` to clean objects files and program file.  

**Execute**: `./push_swap 58 90 -1 4 -592 18 5 6792 -21845` (for example)  

## Help

To sorts the numbers from 1 to 3 (amount of numbers), we just use **conditions**  
![Sort 3](https://user-images.githubusercontent.com/16923245/235941262-0c57ddc0-e4a1-42d1-b94b-7f0fc3a3132b.png "Sort 3")  

To sort numbers from **5 to 40**, I just the **selection sort algorithm** (you can see an explanation [here](https://www.programiz.com/dsa/selection-sort "here"))  

To sort numbers **after 40** I use first the [**Longest Inscreasing Subsequence**](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/ "**Longest Inscreasing Subsequence**"), many explanations can be found on internet but the goal is to **take the longest sequence of numbers that are already sorted**. All the other numbers are moved to the stack B and you get the longest increasing subsequence in your stack. This method reduce a lot your futures operations because you'll not moving the numbers.  
When this part is done, I'm just looking for **the number that needs the least amount of operations possible** to be well-placed in the stack A and I move this one. I repeat the operation **while the stack B** isn't empty.  
When the stack B is empty it means that all numbers are placed in the stack A, we just have to **rotate/rrotate while the minimum is on the top** of the stack A.  
