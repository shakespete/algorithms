# Understanding Big O

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

<p>
Sources:
</p>
- [Big O Notation](https://web.mit.edu/16.070/www/lecture/big_o.pdf)
