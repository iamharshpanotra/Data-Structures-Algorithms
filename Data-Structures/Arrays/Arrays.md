# C++ Arrays -- Complete Guide

## Table of Contents

1.  Introduction
2.  What is an Array?
3.  Memory Representation
4.  Declaration
5.  Initialization
6.  Accessing Elements
7.  Traversing Arrays
8.  Input and Output
9.  Array Size
10. Passing Arrays to Functions
11. Multidimensional Arrays
12. Character Arrays
13. Arrays vs Vectors
14. Common Operations
15. Time & Space Complexity
16. Common Interview Problems
17. Common Mistakes
18. Best Practices
19. Cheat Sheet

------------------------------------------------------------------------

# 1. Introduction

An **array** is a collection of elements of the **same data type**
stored in **contiguous memory locations**.

``` cpp
int marks[5];
```

-   Fixed size
-   Fast random access
-   Index starts from **0**

------------------------------------------------------------------------

# 2. Memory Representation

``` text
Index :   0    1    2    3    4

Value :  10   20   30   40   50

Memory:
1000 1004 1008 1012 1016
```

Address Formula

    Address = Base Address + (Index × Size of datatype)

------------------------------------------------------------------------

# 3. Declaration

``` cpp
int arr[5];
float price[10];
char name[20];
```

------------------------------------------------------------------------

# 4. Initialization

``` cpp
int a[5]={1,2,3,4,5};

int b[]={10,20,30};

int c[5]={1,2};

int d[5]={};
```

------------------------------------------------------------------------

# 5. Accessing Elements

``` cpp
cout<<a[0];
a[2]=100;
```

------------------------------------------------------------------------

# 6. Traversing Arrays

### Using for loop

``` cpp
for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
```

### Range-based loop

``` cpp
for(int x:arr)
    cout<<x<<" ";
```

------------------------------------------------------------------------

# 7. Input

``` cpp
for(int i=0;i<n;i++)
    cin>>arr[i];
```

Output

``` cpp
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
```

------------------------------------------------------------------------

# 8. Finding Size

``` cpp
int arr[5];

int n = sizeof(arr)/sizeof(arr[0]);
```

------------------------------------------------------------------------

# 9. Passing Arrays to Functions

``` cpp
void print(int arr[], int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
```

Equivalent

``` cpp
void print(int* arr,int n)
```

------------------------------------------------------------------------

# 10. Multidimensional Arrays

``` cpp
int matrix[2][3]={
    {1,2,3},
    {4,5,6}
};
```

Traversal

``` cpp
for(int i=0;i<2;i++)
    for(int j=0;j<3;j++)
        cout<<matrix[i][j];
```

------------------------------------------------------------------------

# 11. Character Arrays

``` cpp
char name[]="OpenAI";
```

Null character (`\0`) is automatically added.

------------------------------------------------------------------------

# 12. Arrays vs Vectors

  Feature   Array             Vector
  --------- ----------------- -----------------
  Size      Fixed             Dynamic
  Memory    Contiguous        Contiguous
  Resize    No                Yes
  Speed     Slightly Faster   Slight overhead

------------------------------------------------------------------------

# 13. Common Operations

## Searching

Linear Search

``` cpp
for(int i=0;i<n;i++)
    if(arr[i]==target)
        return i;
```

Binary Search (Sorted Array)

``` cpp
binary_search(arr,arr+n,target);
```

------------------------------------------------------------------------

Sorting

``` cpp
sort(arr,arr+n);
```

Reverse

``` cpp
reverse(arr,arr+n);
```

Maximum

``` cpp
int mx=*max_element(arr,arr+n);
```

Minimum

``` cpp
int mn=*min_element(arr,arr+n);
```

Sum

``` cpp
int sum=accumulate(arr,arr+n,0);
```

Count

``` cpp
count(arr,arr+n,5);
```

------------------------------------------------------------------------

# 14. Time Complexity

  Operation       Complexity
  --------------- ------------
  Access          O(1)
  Update          O(1)
  Traversal       O(n)
  Linear Search   O(n)
  Binary Search   O(log n)
  Sorting         O(n log n)

Space Complexity

    O(n)

------------------------------------------------------------------------

# 15. Popular Interview Problems

-   Reverse Array
-   Rotate Array
-   Move Zeroes
-   Maximum Subarray (Kadane)
-   Two Sum
-   Merge Sorted Arrays
-   Remove Duplicates
-   Leaders in Array
-   Stock Buy Sell
-   Trapping Rain Water
-   Product Except Self
-   Prefix Sum
-   Sliding Window
-   Dutch National Flag
-   Majority Element
-   Missing Number

------------------------------------------------------------------------

# 16. Common Mistakes

❌ Accessing outside array bounds

``` cpp
arr[10];
```

❌ Forgetting zero indexing

❌ Wrong array size calculation after passing to a function

``` cpp
sizeof(arr)
```

Inside a function this gives pointer size, not array size.

------------------------------------------------------------------------

# 17. Best Practices

-   Prefer `std::vector` unless fixed-size arrays are required.
-   Validate indices.
-   Use range-based loops when appropriate.
-   Use standard library algorithms (`sort`, `reverse`, `max_element`,
    etc.).
-   Avoid magic numbers; store array size in a variable or use
    `std::size()` (C++17).

------------------------------------------------------------------------

# 18. Cheat Sheet

``` cpp
int arr[5];

arr[0];

sizeof(arr)/sizeof(arr[0]);

sort(arr,arr+n);

reverse(arr,arr+n);

max_element(arr,arr+n);

min_element(arr,arr+n);

accumulate(arr,arr+n,0);

binary_search(arr,arr+n,x);

for(int x:arr)
    cout<<x;
```

------------------------------------------------------------------------

# Summary

Arrays are one of the most fundamental data structures in C++. Master: -
Declaration - Initialization - Traversal - Searching - Sorting -
Multidimensional arrays - Passing to functions - Complexity analysis -
Common interview patterns

Once comfortable with arrays, the next natural topics are pointers,
vectors, strings, prefix sums, sliding window, hashing, and dynamic
arrays.
