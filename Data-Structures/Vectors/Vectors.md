# C++ Vectors -- Complete Guide

# Table of Contents

1.  Introduction
2.  Why Use Vectors?
3.  Syntax
4.  Declaration
5.  Initialization
6.  Adding Elements
7.  Accessing Elements
8.  Traversal
9.  Capacity vs Size
10. Common Member Functions
11. Iterators
12. Passing Vectors to Functions
13. 2D Vectors
14. STL Algorithms
15. Time & Space Complexity
16. Arrays vs Vectors
17. Common Interview Problems
18. Common Mistakes
19. Best Practices
20. Cheat Sheet

------------------------------------------------------------------------

# 1. Introduction

`std::vector` is a dynamic array provided by the C++ Standard Template
Library (STL).

``` cpp
#include <vector>
using namespace std;
```

Unlike arrays, vectors can grow and shrink automatically.

------------------------------------------------------------------------

# 2. Why Use Vectors?

-   Dynamic size
-   Contiguous memory
-   Fast random access
-   Rich STL support
-   Easy insertion at the end
-   Automatic memory management

------------------------------------------------------------------------

# 3. Syntax

``` cpp
vector<int> nums;
vector<string> names;
vector<double> prices;
```

------------------------------------------------------------------------

# 4. Declaration

``` cpp
vector<int> a;
vector<int> b(5);
vector<int> c(5,10);
vector<int> d={1,2,3,4};
vector<int> e(a);
```

------------------------------------------------------------------------

# 5. Initialization

``` cpp
vector<int> nums={10,20,30};
```

------------------------------------------------------------------------

# 6. Adding Elements

``` cpp
v.push_back(10);
v.emplace_back(20);
```

Insert

``` cpp
v.insert(v.begin()+2,100);
```

------------------------------------------------------------------------

# 7. Accessing Elements

``` cpp
v[0];
v.at(0);
v.front();
v.back();
```

Difference:

-   `[]` doesn't check bounds.
-   `at()` throws an exception on invalid index.

------------------------------------------------------------------------

# 8. Traversal

Index loop

``` cpp
for(int i=0;i<v.size();i++)
    cout<<v[i];
```

Range loop

``` cpp
for(int x:v)
    cout<<x;
```

Iterator

``` cpp
for(auto it=v.begin();it!=v.end();it++)
    cout<<*it;
```

------------------------------------------------------------------------

# 9. Size vs Capacity

``` cpp
v.size();
v.capacity();
v.empty();
```

Reserve memory

``` cpp
v.reserve(100);
```

Shrink unused memory

``` cpp
v.shrink_to_fit();
```

------------------------------------------------------------------------

# 10. Important Functions

``` cpp
push_back()
emplace_back()
pop_back()
insert()
erase()
clear()
resize()
assign()
swap()
front()
back()
data()
size()
capacity()
empty()
reserve()
```

Examples

``` cpp
v.pop_back();
v.clear();
v.resize(10);
```

------------------------------------------------------------------------

# 11. Iterators

``` cpp
begin()
end()
rbegin()
rend()
cbegin()
cend()
```

------------------------------------------------------------------------

# 12. Passing to Functions

Copy

``` cpp
void print(vector<int> v)
```

Reference

``` cpp
void print(vector<int>& v)
```

Const Reference

``` cpp
void print(const vector<int>& v)
```

------------------------------------------------------------------------

# 13. 2D Vectors

``` cpp
vector<vector<int>> matrix={
    {1,2,3},
    {4,5,6}
};
```

Traversal

``` cpp
for(auto &row:matrix)
    for(int x:row)
        cout<<x<<" ";
```

------------------------------------------------------------------------

# 14. STL Algorithms

Sort

``` cpp
sort(v.begin(),v.end());
```

Reverse

``` cpp
reverse(v.begin(),v.end());
```

Find

``` cpp
find(v.begin(),v.end(),10);
```

Binary Search

``` cpp
binary_search(v.begin(),v.end(),10);
```

Maximum

``` cpp
*max_element(v.begin(),v.end());
```

Minimum

``` cpp
*min_element(v.begin(),v.end());
```

Sum

``` cpp
accumulate(v.begin(),v.end(),0);
```

Unique

``` cpp
v.erase(unique(v.begin(),v.end()),v.end());
```

------------------------------------------------------------------------

# 15. Time & Space Complexity

  Operation               Complexity
  ----------------------- ------------
  Access                  O(1)
  push_back (amortized)   O(1)
  pop_back                O(1)
  Insert at beginning     O(n)
  Insert middle           O(n)
  Erase                   O(n)
  Traversal               O(n)
  Sort                    O(n log n)
  Search                  O(n)
  Binary Search           O(log n)

Space: O(n)

------------------------------------------------------------------------

# 16. Arrays vs Vectors

  Feature       Array        Vector
  ------------- ------------ ------------
  Size          Fixed        Dynamic
  Resize        No           Yes
  STL Support   Limited      Excellent
  Memory        Contiguous   Contiguous

------------------------------------------------------------------------

# 17. Popular Interview Problems

-   Two Sum
-   Rotate Array
-   Merge Intervals
-   Product Except Self
-   Majority Element
-   Move Zeroes
-   Remove Duplicates
-   Next Permutation
-   Spiral Matrix
-   Prefix Sum
-   Sliding Window
-   Merge Sorted Arrays

------------------------------------------------------------------------

# 18. Common Mistakes

-   Using `[]` for unsafe access.
-   Forgetting vectors reallocate and invalidate iterators.
-   Passing vectors by value unnecessarily.
-   Calling `back()` on an empty vector.
-   Confusing `size()` with `capacity()`.

------------------------------------------------------------------------

# 19. Best Practices

-   Prefer `emplace_back()` for object construction.
-   Pass large vectors by `const&`.
-   Call `reserve()` when size is known.
-   Use STL algorithms instead of manual loops.
-   Prefer range-based loops for readability.

------------------------------------------------------------------------

# 20. Cheat Sheet

``` cpp
vector<int> v;

v.push_back(10);
v.emplace_back(20);

v.pop_back();

v.size();
v.capacity();
v.empty();

v.front();
v.back();

sort(v.begin(),v.end());
reverse(v.begin(),v.end());

find(v.begin(),v.end(),x);

binary_search(v.begin(),v.end(),x);

v.erase(v.begin()+2);

v.clear();

v.resize(10);

v.reserve(100);
```

------------------------------------------------------------------------

# Summary

Vectors are the most commonly used container in modern C++. They provide
dynamic storage, efficient random access, seamless integration with STL
algorithms, and are the preferred replacement for raw arrays in most
applications. Master vectors before moving on to strings, maps, sets,
stacks, queues, heaps, and graphs.
