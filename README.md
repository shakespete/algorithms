# Understanding Big O

<p align="center">
<img src="https://github.com/shakespete/algorithms/blob/dev/img/big_o.png" align="center" >
</p>
<p align="center">
<img src="https://github.com/shakespete/algorithms/blob/dev/img/sorting_complexity.png" width="800px" height="auto" align="center" >
</p>

Source: https://www.bigocheatsheet.com/
<br />

## Introduction
How efficient is an algorithm or piece of code? Efficiency covers lots of resources,
including:

- CPU (time) usage
- memory usage
- disk usage
- network usage

<p>
All are important but we will mostly talk about time complexity (CPU usage).
Be careful to differentiate between:
1. Performance: how much time/memory/disk/... is actually used when a program is
run. This depends on the machine, compiler, etc. as well as the code.
2. Complexity: how do the resource requirements of a program or algorithm scale,
i.e., what happens as the size of the problem being solved gets larger?
</p>

<p>
Complexity affects performance but not the other way around.
The time required by a function/procedure is proportional to the number of "basic
operations" that it performs. Here are some examples of basic operations:
</p>

- one arithmetic operation (e.g., +, *)
- one assignment (e.g. x := 0)
- one test (e.g., x = 0)
- one read (of a primitive type: integer, float, character, boolean)
- one write (of a primitive type: integer, float, character, boolean)

<p>
Some functions/procedures perform the same number of operations every time they are
called. For example, StackSize in the Stack implementation always returns the number of
elements currently in the stack or states that the stack is empty, then we say that
StackSize takes constant time.
</p>

<p>
Other functions/ procedures may perform different numbers of operations, depending on
the value of a parameter. For example, in the BubbleSort algorithm, the number of
elements in the array, determines the number of operations performed by the algorithm.
This parameter (number of elements) is called the problem size/ input size.
</p>

<p>
When we are trying to find the complexity of the function/ procedure/ algorithm/
program, we are not interested in the exact number of operations that are being
performed. Instead, we are interested in the relation of the number of operations to the
problem size.
</p>

<p>
Typically, we are usually interested in the worst case: what is the maximum number of
operations that might be performed for a given problem size. For example, inserting an
element into an array, we have to move the current element and all of the elements that
come after it one place to the right in the array. In the worst case, inserting at the
beginning of the array, all of the elements in the array must be moved. Therefore, in the
worst case, the time for insertion is proportional to the number of elements in the array,
and we say that the worst-case time for the insertion operation is linear in the number of
elements in the array. For a linear-time algorithm, if the problem size doubles, the
number of operations also doubles.
</p>

## Big-O Notation

We express complexity using big-O notation.

For a problem of size N:
- a constant-time algorithm is "order 1": O(1)
- a linear-time algorithm is "order N": O(N)
- a quadratic-time algorithm is "order N squared": O(N^2)

<p>
Note that the big-O expressions do not have constants or low-order terms. This is
because, when N gets large enough, constants and low-order terms don't matter (a
constant-time algorithm will be faster than a linear-time algorithm, which will be faster
than a quadratic-time algorithm).
</p>

## How to Determine Complexities

<p>
In general, how can you determine the running time of a piece of code? The answer is
that it depends on what kinds of statements are used.
</p>

### Sequence of statements

statement 1;
statement 2;
...
statement k;
<p>
The total time is found by adding the times for all statements:
</p>

**_total time = time(statement 1) + time(statement 2) + ... + time(statement k)_**

<p>
If each statement is "simple" (only involves basic operations) then the time for each
statement is constant and the total time is also constant: O(1).
</p>

### If-Then-Else
```
if (cond) then
  block 1 (sequence of statements)
else
  block 2 (sequence of statements)
end if;
```
<p>
Here, either block 1 will execute, or block 2 will execute. Therefore, the worst-case time
is the slower of the two possibilities:
</p>

**_max(time(block 1), time(block 2))_**

<p>If block 1 takes O(1) and block 2 takes O(N), the if-then-else statement would be O(N)</p>

### Loops

```
for I in 1 .. N loop
  sequence of statements
end loop;
```

<p>
The loop executes N times, so the sequence of statements also executes N times. If we
assume the statements are O(1), the total time for the for loop is N * O(1), which is O(N)
overall.
</p>

### Nested Loops

```
for I in 1 .. N loop
  for J in 1 .. M loop
    sequence of statements
  end loop;
end loop;
```
<p>
The outer loop executes N times. Every time the outer loop executes, the inner loop
executes M times. As a result, the statements in the inner loop execute a total of N * M
times. Thus, the complexity is O(N * M).
</p>
<p>
In a common special case where the stopping condition of the inner loop is J < N instead
of J < M (i.e., the inner loop also executes N times), the total complexity for the two loops
is O(N^2)
</p>


<p>
Sources:
</p>
- [Big O Notation](https://web.mit.edu/16.070/www/lecture/big_o.pdf)
