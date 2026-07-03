# C++ Standard Template Library (STL)

> The Standard Template Library (STL) is one of the most important parts of C++. It provides ready-made implementations of common data structures and algorithms, making programming faster, safer, and more efficient.

---

# Table of Contents

1. Introduction
2. Components of STL
3. Containers
4. Container Adapters
5. Iterators
6. Algorithms
7. Function Objects (Functors)
8. Lambda Expressions
9. Utility Library
10. Pair
11. Tuple
12. Optional
13. Variant
14. Any
15. String
16. Bitset
17. Numeric Library
18. Memory Utilities
19. Allocators
20. Time Complexity Table
21. STL Cheat Sheet
22. Interview Questions
23. Best Practices

---

# 1. Introduction

STL consists of generic template classes and functions.

Advantages

- Reusable
- Fast
- Optimized
- Type-safe
- Reduces code
- Widely used in DSA

Example

```cpp
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums = {4,2,6,1};

    sort(nums.begin(), nums.end());

    for(auto x : nums)
        cout << x << " ";
}
```

Output

```
1 2 4 6
```

---

# 2. Components of STL

STL has four major components.

```
STL
│
├── Containers
├── Iterators
├── Algorithms
└── Function Objects
```

---

# 3. Containers

Containers store data.

Three categories

```
Containers
│
├── Sequence
├── Associative
└── Unordered
```

---

# Sequence Containers

## Array

Header

```cpp
#include <array>
```

Fixed size.

```cpp
array<int,5> arr={1,2,3,4,5};
```

Functions

```
at()
front()
back()
fill()
swap()
size()
empty()
```

Complexity

Access

O(1)

---

## Vector

Header

```cpp
#include <vector>
```

Dynamic array.

```cpp
vector<int> v;
```

Functions

```
push_back()

pop_back()

size()

capacity()

reserve()

resize()

clear()

erase()

insert()

begin()

end()

front()

back()

empty()
```

Complexities

Push Back

Amortized O(1)

Random Access

O(1)

Insertion Middle

O(n)

Deletion Middle

O(n)

---

## Deque

Header

```cpp
#include <deque>
```

Double ended queue.

Supports insertion at both ends.

```
push_front()

push_back()

pop_front()

pop_back()
```

Complexities

Insert front

O(1)

Insert back

O(1)

Random Access

O(1)

---

## List

Header

```cpp
#include <list>
```

Doubly linked list.

```
push_back()

push_front()

pop_back()

pop_front()

sort()

reverse()

merge()

splice()
```

Complexities

Insertion

O(1)

Deletion

O(1)

Random Access

Not Supported

---

## Forward List

Header

```cpp
#include <forward_list>
```

Singly linked list.

Less memory than list.

---

# Associative Containers

Automatically sorted.

Implemented using Red Black Trees.

Operations

O(log n)

---

## Set

Unique values.

```cpp
set<int> s;
```

Functions

```
insert()

erase()

find()

count()

lower_bound()

upper_bound()
```

---

## Multiset

Allows duplicates.

```
multiset<int>
```

---

## Map

Key Value pair.

```cpp
map<string,int> mp;
```

Example

```cpp
mp["Apple"]=10;
```

---

## Multimap

Duplicate keys allowed.

---

# Unordered Containers

Implemented using Hash Tables.

Average Complexity

O(1)

Worst

O(n)

---

## unordered_set

```cpp
unordered_set<int>
```

---

## unordered_multiset

Duplicates allowed.

---

## unordered_map

```cpp
unordered_map<int,string>
```

---

## unordered_multimap

Duplicate keys allowed.

---

# 4. Container Adapters

These are built on top of other containers.

---

## Stack

LIFO

Header

```cpp
#include <stack>
```

Functions

```
push()

pop()

top()

empty()

size()
```

Complexities

Push

O(1)

Pop

O(1)

---

## Queue

FIFO

Header

```cpp
#include <queue>
```

Functions

```
push()

pop()

front()

back()
```

---

## Priority Queue

Heap

Default

Max Heap

```cpp
priority_queue<int> pq;
```

Min Heap

```cpp
priority_queue<
int,
vector<int>,
greater<int>
> pq;
```

Operations

```
push()

pop()

top()
```

Complexities

Insert

O(log n)

Delete

O(log n)

Top

O(1)

---

# 5. Iterators

Iterator acts like a pointer.

Types

```
begin()

end()

cbegin()

cend()

rbegin()

rend()
```

Example

```cpp
vector<int> v={1,2,3};

for(auto it=v.begin();it!=v.end();it++)
    cout<<*it;
```

Iterator Categories

```
Input
Output
Forward
Bidirectional
Random Access
Contiguous (C++20)
```

---

# 6. Algorithms

Header

```cpp
#include <algorithm>
```

---

Sorting

```
sort()

stable_sort()

partial_sort()

nth_element()
```

---

Searching

```
binary_search()

lower_bound()

upper_bound()

equal_range()

find()

find_if()

count()

count_if()
```

---

Min Max

```
min()

max()

min_element()

max_element()
```

---

Permutation

```
next_permutation()

prev_permutation()
```

---

Heap

```
make_heap()

push_heap()

pop_heap()

sort_heap()
```

---

Reverse

```
reverse()

rotate()
```

---

Remove

```
remove()

remove_if()

unique()
```

---

Copy

```
copy()

copy_if()

move()

swap()
```

---

Fill

```
fill()

generate()

iota()
```

---

Partition

```
partition()

stable_partition()
```

---

Comparison

```
equal()

lexicographical_compare()
```

---

# 7. Function Objects (Functors)

Objects that behave like functions.

Example

```cpp
struct Add
{
    int operator()(int a,int b)
    {
        return a+b;
    }
};
```

---

# 8. Lambda Expressions

Syntax

```cpp
[capture](parameters)
{
    body
};
```

Example

```cpp
sort(v.begin(),v.end(),
[](int a,int b)
{
    return a>b;
});
```

Captures

```
[]
[=]
[&]
[x]
[&x]
```

---

# 9. Utility Library

Header

```cpp
#include <utility>
```

Contains

```
pair

swap

move

forward
```

---

# 10. Pair

```cpp
pair<int,string> p;
```

Example

```cpp
pair<int,string> p={1,"One"};
```

Access

```
first

second
```

---

# 11. Tuple

Stores multiple values.

```cpp
tuple<int,string,double>
```

Functions

```
get<>()

tie()

make_tuple()
```

---

# 12. Optional (C++17)

Represents optional value.

```cpp
optional<int>
```

Functions

```
has_value()

value()

reset()
```

---

# 13. Variant

Can store one of many types.

```cpp
variant<int,string>
```

---

# 14. Any

Can hold any datatype.

```cpp
any a=10;
```

---

# 15. String

Header

```cpp
#include <string>
```

Functions

```
length()

size()

substr()

find()

erase()

insert()

replace()

append()

push_back()

pop_back()

compare()
```

---

# 16. Bitset

Efficient bit operations.

```cpp
bitset<8> b("10101010");
```

Functions

```
count()

set()

reset()

flip()

test()
```

---

# 17. Numeric Library

Header

```cpp
#include <numeric>
```

Functions

```
accumulate()

iota()

gcd()

lcm()

inner_product()

partial_sum()

adjacent_difference()

reduce()

exclusive_scan()

inclusive_scan()
```

---

# 18. Memory Utilities

Smart pointers

```
unique_ptr

shared_ptr

weak_ptr
```

Headers

```cpp
#include <memory>
```

---

# 19. Allocators

Custom memory allocation.

Rarely used directly.

```cpp
allocator<int>
```

---

# 20. Time Complexity Table

| Container | Insert | Delete | Search | Random Access |
|------------|---------|---------|---------|---------------|
| Array | O(1) | O(n) | O(n) | O(1) |
| Vector | O(1)* | O(n) | O(n) | O(1) |
| Deque | O(1) | O(1) | O(n) | O(1) |
| List | O(1) | O(1) | O(n) | No |
| Forward List | O(1) | O(1) | O(n) | No |
| Set | O(log n) | O(log n) | O(log n) | No |
| Map | O(log n) | O(log n) | O(log n) | No |
| Unordered Map | O(1)* | O(1)* | O(1)* | No |
| Priority Queue | O(log n) | O(log n) | O(1) Top | No |

---

# 21. STL Cheat Sheet

Sequence

```
array
vector
deque
list
forward_list
```

Associative

```
set
multiset
map
multimap
```

Unordered

```
unordered_set
unordered_multiset
unordered_map
unordered_multimap
```

Adapters

```
stack
queue
priority_queue
```

Algorithms

```
sort
find
count
binary_search
lower_bound
upper_bound
reverse
rotate
remove
unique
accumulate
iota
next_permutation
```

Utilities

```
pair
tuple
optional
variant
any
bitset
```

---

# 22. Frequently Asked Interview Questions

## Why use vector instead of array?

- Dynamic size
- STL support
- Better usability

---

## map vs unordered_map

| map | unordered_map |
|------|---------------|
| Sorted | Unsorted |
| O(log n) | Average O(1) |
| Tree | Hash Table |

---

## set vs unordered_set

| set | unordered_set |
|------|---------------|
| Sorted | Unsorted |
| O(log n) | Average O(1) |

---

## vector vs deque

| vector | deque |
|---------|-------|
| Fast back insertion | Fast front & back insertion |
| Contiguous memory | Segmented memory |

---

## list vs vector

Vector

- Better cache locality
- Random access

List

- Fast insertion/deletion
- No random access

---

## When to use Priority Queue?

- Dijkstra
- Huffman Coding
- Scheduling
- Top K Problems
- Median Problems
- Heap Problems

---

# 23. Best Practices

✔ Prefer vector over array unless fixed size is required.

✔ Use unordered_map for fast lookup.

✔ Use map when sorted order is required.

✔ Reserve vector capacity if size is known.

```cpp
vector<int> v;
v.reserve(100000);
```

✔ Pass containers by reference.

```cpp
void solve(vector<int>& nums)
```

✔ Use auto for iterators.

```cpp
for(auto it=v.begin();it!=v.end();it++)
```

✔ Prefer range-based loops.

```cpp
for(auto x:v)
```

✔ Use emplace() / emplace_back() to avoid unnecessary copies.

```cpp
v.emplace_back(10);
```

✔ Avoid copying large containers.

Instead of

```cpp
vector<int> copy=v;
```

Use

```cpp
vector<int>& ref=v;
```

---

# STL Learning Order

```
Arrays
      ↓
Vectors
      ↓
Strings
      ↓
Pairs
      ↓
Maps
      ↓
Sets
      ↓
Queues
      ↓
Stacks
      ↓
Priority Queue
      ↓
Deque
      ↓
List
      ↓
Algorithms
      ↓
Iterators
      ↓
Lambdas
      ↓
Functors
      ↓
Bitset
      ↓
Tuple
      ↓
Optional
      ↓
Variant
      ↓
Any
      ↓
Memory Utilities
```

---

# Final Summary

Master these topics to become proficient in C++ STL:

- Arrays
- Vector
- String
- Pair
- Map
- Unordered Map
- Set
- Unordered Set
- Multiset
- Queue
- Stack
- Priority Queue
- Deque
- List
- Forward List
- Iterators
- Algorithms
- Lambda Functions
- Functors
- Pair & Tuple
- Optional
- Variant
- Any
- Bitset
- Numeric Library
- Smart Pointers
- Memory Utilities
- Time Complexity
- STL Best Practices

Mastering STL significantly improves coding speed and problem-solving efficiency in DSA, competitive programming, and technical interviews.