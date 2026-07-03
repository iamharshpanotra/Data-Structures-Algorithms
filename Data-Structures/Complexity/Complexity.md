# Time Complexity and Space Complexity in C++

> **Goal:** Learn how to analyze the efficiency of algorithms in terms of **execution time** and **memory usage**.

---

# Table of Contents

1. Introduction
2. Why Complexity Analysis?
3. Time Complexity
4. Space Complexity
5. Big-O, Big-Ω, and Big-Θ
6. Common Time Complexities
7. Common Space Complexities
8. Rules for Calculating Time Complexity
9. Rules for Calculating Space Complexity
10. Complexity of Common Loops
11. Complexity of Recursion
12. Complexity of STL Containers
13. Complexity of STL Algorithms
14. Best, Average, and Worst Case
15. Amortized Complexity
16. Examples with C++
17. Interview Tips
18. Cheat Sheet

---

# 1. Introduction

Whenever we write a program, we want answers to two questions:

* How fast does it run?
* How much memory does it consume?

These are measured using:

* **Time Complexity**
* **Space Complexity**

Instead of measuring actual seconds or MBs (which depend on hardware), computer science measures **how performance grows as the input size (N) increases.**

---

# 2. Why Complexity Analysis?

Suppose two algorithms solve the same problem.

Algorithm A

```cpp
Runs in 0.001 seconds for N = 100
Runs in 10 seconds for N = 1,000,000
```

Algorithm B

```cpp
Runs in 0.1 seconds for N = 100
Runs in 0.5 seconds for N = 1,000,000
```

Although Algorithm A starts faster, Algorithm B scales much better.

Complexity analysis helps us predict this behavior.

---

# 3. Time Complexity

Time Complexity measures how the running time increases with input size.

It **does NOT** measure actual seconds.

Instead it measures **growth rate**.

Notation:

```
O(1)
O(log N)
O(N)
O(N log N)
O(N²)
O(2^N)
O(N!)
```

Example

```cpp
int sum = 0;

for(int i = 0; i < n; i++)
{
    sum += arr[i];
}
```

Loop executes N times.

Time Complexity:

```
O(N)
```

---

# 4. Space Complexity

Space Complexity measures the extra memory required.

It includes

* Variables
* Arrays
* Vectors
* Recursion stack
* Dynamic memory

Example

```cpp
int x = 10;
int y = 20;
```

Only two variables.

Space Complexity

```
O(1)
```

Example

```cpp
vector<int> v(n);
```

Stores N integers.

Space Complexity

```
O(N)
```

---

# 5. Big-O, Big-Ω and Big-Θ

## Big-O (Upper Bound)

Worst-case complexity.

Example

```
Binary Search

Worst Case = O(log N)
```

---

## Big-Ω (Lower Bound)

Best-case complexity.

Example

Searching first element.

```
Ω(1)
```

---

## Big-Θ (Tight Bound)

Average exact growth.

Example

Merge Sort

```
Θ(N log N)
```

---

# 6. Common Time Complexities

## O(1) — Constant

Independent of input size.

```cpp
return arr[0];
```

Very fast.

---

## O(log N) — Logarithmic

Problem size halves every step.

Example

* Binary Search
* Balanced BST

```cpp
while(low <= high)
{
    int mid = (low + high)/2;
}
```

---

## O(√N)

Common in mathematics.

Example

Prime checking.

```cpp
for(int i=2;i*i<=n;i++)
```

---

## O(N)

Linear growth.

```cpp
for(int i=0;i<n;i++)
```

Examples

* Finding maximum
* Sum of array
* Linear Search

---

## O(N log N)

Efficient sorting.

Examples

* Merge Sort
* Heap Sort
* Average Quick Sort

---

## O(N²)

Nested loops.

```cpp
for(...)
{
    for(...)
    {

    }
}
```

Examples

* Bubble Sort
* Selection Sort
* Insertion Sort (Worst)

---

## O(N³)

Triple nested loops.

Often seen in matrix multiplication.

---

## O(2^N)

Every element has two choices.

Examples

* Recursive Fibonacci
* Subset generation

---

## O(N!)

All permutations.

Example

Travelling Salesman (Brute Force)

---

# 7. Common Space Complexities

## O(1)

Only fixed variables.

```cpp
int a;
int b;
```

---

## O(log N)

Recursion stack.

Binary Search recursion.

---

## O(N)

Array

```cpp
vector<int> v(n);
```

---

## O(N²)

Matrix

```cpp
int matrix[n][n];
```

---

# 8. Rules for Calculating Time Complexity

## Rule 1

Ignore constants.

```
O(2N)

becomes

O(N)
```

---

## Rule 2

Ignore lower-order terms.

```
O(N² + N + 10)

becomes

O(N²)
```

---

## Rule 3

Sequential loops add.

```cpp
for(...)
for(...)
```

```
O(N + N)

=

O(N)
```

---

## Rule 4

Nested loops multiply.

```cpp
for(...)
{
    for(...)
}
```

```
O(N²)
```

---

## Rule 5

Different variables remain separate.

```cpp
for(i<n)
for(j<m)
```

```
O(N + M)
```

---

# 9. Rules for Calculating Space Complexity

Count

* Arrays
* Vectors
* Hash Maps
* Queues
* Stacks
* Recursion

Ignore

* Input itself (unless copied)
* Constant variables

---

# 10. Complexity of Common Loops

Single loop

```cpp
for(int i=0;i<n;i++)
```

```
O(N)
```

---

Nested loop

```cpp
for(i)
{
    for(j)
}
```

```
O(N²)
```

---

Halving loop

```cpp
while(n>1)
{
    n/=2;
}
```

```
O(log N)
```

---

Doubling loop

```cpp
for(int i=1;i<n;i*=2)
```

```
O(log N)
```

---

Square Root loop

```cpp
for(int i=1;i*i<=n;i++)
```

```
O(√N)
```

---

# 11. Complexity of Recursion

Recursive Fibonacci

```cpp
fib(n)
{
    fib(n-1);
    fib(n-2);
}
```

Time

```
O(2^N)
```

Space

```
O(N)
```

(Stack)

---

Merge Sort

Time

```
O(N log N)
```

Space

```
O(N)
```

---

Quick Sort

Average

```
O(N log N)
```

Worst

```
O(N²)
```

Space

```
O(log N)
```

---

# 12. Complexity of STL Containers

| Container      | Search   | Insert   | Delete   |
| -------------- | -------- | -------- | -------- |
| Array          | O(N)     | O(N)     | O(N)     |
| Vector (end)   | O(N)     | O(1)*    | O(1)     |
| Stack          | O(N)     | O(1)     | O(1)     |
| Queue          | O(N)     | O(1)     | O(1)     |
| Deque          | O(N)     | O(1)     | O(1)     |
| Set            | O(log N) | O(log N) | O(log N) |
| Multiset       | O(log N) | O(log N) | O(log N) |
| Map            | O(log N) | O(log N) | O(log N) |
| Multimap       | O(log N) | O(log N) | O(log N) |
| Unordered Set  | O(1)*    | O(1)*    | O(1)*    |
| Unordered Map  | O(1)*    | O(1)*    | O(1)*    |
| Priority Queue | O(N)     | O(log N) | O(log N) |

*Average case

---

# 13. Complexity of STL Algorithms

| Algorithm          | Complexity |
| ------------------ | ---------- |
| sort()             | O(N log N) |
| stable_sort()      | O(N log N) |
| reverse()          | O(N)       |
| find()             | O(N)       |
| binary_search()    | O(log N)   |
| lower_bound()      | O(log N)   |
| upper_bound()      | O(log N)   |
| min_element()      | O(N)       |
| max_element()      | O(N)       |
| count()            | O(N)       |
| accumulate()       | O(N)       |
| next_permutation() | O(N)       |

---

# 14. Best, Average and Worst Case

Example

Linear Search

Best

```
O(1)
```

Average

```
O(N)
```

Worst

```
O(N)
```

---

Binary Search

Best

```
O(1)
```

Worst

```
O(log N)
```

---

# 15. Amortized Complexity

Sometimes one operation is expensive, but many operations together are efficient.

Example

```cpp
vector.push_back()
```

Normally

```
O(1)
```

Occasionally resizing occurs

```
O(N)
```

Overall average

```
Amortized O(1)
```

---

# 16. Examples with C++

## Example 1

```cpp
int x = arr[5];
```

Time

```
O(1)
```

Space

```
O(1)
```

---

## Example 2

```cpp
for(int i=0;i<n;i++)
{
    cout<<arr[i];
}
```

Time

```
O(N)
```

Space

```
O(1)
```

---

## Example 3

```cpp
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cout<<i<<j;
    }
}
```

Time

```
O(N²)
```

Space

```
O(1)
```

---

## Example 4

```cpp
vector<int> temp(n);
```

Time

```
O(N)
```

Space

```
O(N)
```

---

## Example 5

```cpp
unordered_map<int,int> mp;

for(int x : arr)
{
    mp[x]++;
}
```

Time

```
O(N)
```

Space

```
O(N)
```

---

# 17. Interview Tips

* Always mention **worst-case** time complexity unless asked otherwise.
* Ignore constants while calculating Big-O.
* Ignore lower-order terms.
* Count nested loops carefully.
* Recursion also consumes stack memory.
* Extra data structures affect space complexity.
* Distinguish between average-case and worst-case for hash tables and quicksort.
* Optimize only after identifying the bottleneck.

---

# 18. Complexity Cheat Sheet

| Complexity | Name         | Performance |
| ---------- | ------------ | ----------- |
| O(1)       | Constant     | ⭐⭐⭐⭐⭐       |
| O(log N)   | Logarithmic  | ⭐⭐⭐⭐⭐       |
| O(√N)      | Square Root  | ⭐⭐⭐⭐        |
| O(N)       | Linear       | ⭐⭐⭐⭐        |
| O(N log N) | Linearithmic | ⭐⭐⭐         |
| O(N²)      | Quadratic    | ⭐⭐          |
| O(N³)      | Cubic        | ⭐           |
| O(2^N)     | Exponential  | ❌           |
| O(N!)      | Factorial    | ❌❌          |

---

# Memory Tricks

### Time Complexity

* **O(1)** → No growth
* **O(log N)** → Halving
* **O(N)** → One loop
* **O(N log N)** → Divide + Merge
* **O(N²)** → Two nested loops
* **O(2^N)** → Two recursive choices
* **O(N!)** → Permutations

### Space Complexity

* Variables → **O(1)**
* Array of N → **O(N)**
* Matrix → **O(N²)**
* Recursion Depth N → **O(N)**
* HashMap with N elements → **O(N)**

---

# Final Takeaway

When solving Data Structures and Algorithms problems, always analyze both **Time Complexity** and **Space Complexity**. Aim for solutions that scale efficiently as the input size grows. In interviews, explaining *why* an algorithm has a particular complexity is often as important as writing correct code. Developing the habit of estimating complexity before and after coding will make you a stronger problem solver.
