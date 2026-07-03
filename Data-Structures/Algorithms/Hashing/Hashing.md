# Hashing in C++ - The Complete Guide

---

# Table of Contents

1. Introduction to Hashing
2. Why Hashing?
3. What is a Hash Function?
4. Hash Table
5. Collision Handling
6. Hash Containers in C++
7. unordered_map
8. unordered_set
9. map vs unordered_map
10. set vs unordered_set
11. Common Hash Patterns
12. Frequency Counting
13. Duplicate Detection
14. Store Index Pattern
15. Prefix Sum + Hashing
16. Character Hashing
17. Custom Object Hashing
18. STL Hash Functions
19. Time Complexity
20. Common Interview Problems
21. Common Mistakes
22. Best Practices
23. Summary

---

# 1. Introduction to Hashing

Hashing is a technique used to store and retrieve data extremely quickly.

Instead of searching every element one by one, hashing calculates where the data should be stored.

Imagine a library.

Without hashing:

```
Book A
Book B
Book C
Book D
Book E

Need Book D?

Search every book.
```

With hashing:

```
Shelf 15 → Book D

Go directly to Shelf 15.
```

This makes searching nearly **O(1)**.

---

# 2. Why Hashing?

Without hashing

```
Find number 90

1
5
17
25
90

Worst Case = O(n)
```

With hashing

```
Hash(90)

↓

Index = 12

↓

Go directly.
```

Average Time

```
O(1)
```

---

# 3. What is a Hash Function?

A hash function converts a key into an index.

Example

```
Hash(Key) → Index
```

Example

```
Key = 45

Hash = 45 % 10

Index = 5
```

Another example

```
Hash("Apple")

↓

125634

↓

Bucket 14
```

---

# 4. Hash Table

A hash table stores values inside buckets.

```
Index

0

1

2

3

4

5

6

7

8

9
```

Suppose

```
Insert 15

15 % 10 = 5

Store at Bucket 5
```

Insert

```
25

25 % 10 = 5
```

Now both want bucket 5.

This is called a collision.

---

# 5. Collision Handling

Two keys can generate the same hash.

Example

```
15

25

35

Hash

↓

5
```

There are two popular methods.

## Separate Chaining

```
Bucket 5

15

↓

25

↓

35
```

Uses linked lists (or vectors internally).

---

## Open Addressing

Instead of storing in a list,

find another empty bucket.

```
Bucket 5 occupied

↓

Bucket 6

↓

Store there.
```

---

# 6. Hash Containers in C++

C++ provides four important containers.

```
unordered_map

unordered_set

map

set
```

Hash-based

```
unordered_map

unordered_set
```

Tree-based

```
map

set
```

---

# 7. unordered_map

Stores

```
Key → Value
```

Example

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int,int> mp;

mp[1]=100;
mp[2]=200;
mp[3]=300;

cout<<mp[2];
```

Output

```
200
```

---

## Operations

Insert

```cpp
mp[5]=10;
```

Update

```cpp
mp[5]=20;
```

Access

```cpp
cout<<mp[5];
```

Find

```cpp
if(mp.find(5)!=mp.end())
{
    cout<<"Found";
}
```

Erase

```cpp
mp.erase(5);
```

Size

```cpp
mp.size();
```

Empty

```cpp
mp.empty();
```

Clear

```cpp
mp.clear();
```

---

## Traversing

```cpp
for(auto x: mp)
{
    cout<<x.first<<" "<<x.second<<endl;
}
```

Output

```
Key Value
```

---

# 8. unordered_set

Stores only unique values.

```cpp
unordered_set<int> st;

st.insert(5);
st.insert(10);
st.insert(5);
```

Result

```
5

10
```

Duplicate is ignored.

---

Operations

Insert

```cpp
st.insert(7);
```

Search

```cpp
st.count(7);
```

Erase

```cpp
st.erase(7);
```

Find

```cpp
st.find(7);
```

---

Traversal

```cpp
for(auto x: st)
{
    cout<<x;
}
```

---

# 9. map vs unordered_map

| Feature | map | unordered_map |
|----------|-----|---------------|
| Implementation | Red Black Tree | Hash Table |
| Sorted | Yes | No |
| Insert | O(log n) | O(1) Avg |
| Search | O(log n) | O(1) Avg |
| Delete | O(log n) | O(1) Avg |
| Ordering | Sorted | Random |

---

# 10. set vs unordered_set

| Feature | set | unordered_set |
|----------|-----|---------------|
| Sorted | Yes | No |
| Duplicate | No | No |
| Search | O(log n) | O(1) Avg |

---

# 11. Hash Pattern

General Template

```cpp
unordered_map<Key, Value> hash;

for(each element)
{
    if(answer exists)
        return;

    store current element;
}
```

---

# 12. Frequency Counting

Most common pattern.

Problem

```
2 4 2 5 6 2 4
```

Need frequency.

Solution

```cpp
unordered_map<int,int> freq;

for(int num: nums)
{
    freq[num]++;
}
```

Result

```
2 → 3

4 → 2

5 → 1

6 → 1
```

Applications

- Top K Frequent
- Majority Element
- Character Counting

---

# 13. Duplicate Detection

Problem

```
4 7 1 9 7
```

Solution

```cpp
unordered_set<int> seen;

for(int num: nums)
{
    if(seen.count(num))
        return true;

    seen.insert(num);
}
```

Time

```
O(n)
```

---

# 14. Store Index Pattern

Used in Two Sum.

Problem

```
2 7 11 15

Target = 9
```

Store

```
Value → Index
```

Solution

```cpp
unordered_map<int,int> mp;

for(int i=0;i<nums.size();i++)
{
    int need=target-nums[i];

    if(mp.find(need)!=mp.end())
        return {mp[need],i};

    mp[nums[i]]=i;
}
```

---

# 15. Prefix Sum + Hashing

Problem

Find subarray sum = K

Example

```
2 3 1 2

K=5
```

Store prefix sums.

```cpp
unordered_map<int,int> prefix;

prefix[0]=-1;

int sum=0;

for(int i=0;i<n;i++)
{
    sum+=nums[i];

    if(prefix.count(sum-k))
    {
        cout<<"Found";
    }

    prefix[sum]=i;
}
```

Applications

- Subarray Sum Equals K
- Longest Subarray
- Continuous Subarray Sum

---

# 16. Character Hashing

Problem

```
banana
```

Solution

```cpp
unordered_map<char,int> freq;

for(char c:s)
{
    freq[c]++;
}
```

Output

```
b→1

a→3

n→2
```

Applications

- Valid Anagram
- Group Anagrams
- First Unique Character

---

# 17. Custom Object Hashing

Suppose

```cpp
pair<int,int>
```

We need our own hash.

```cpp
struct PairHash
{
    size_t operator()(const pair<int,int>& p) const
    {
        return hash<int>()(p.first)^hash<int>()(p.second);
    }
};
```

Use

```cpp
unordered_map<pair<int,int>,int,PairHash> mp;
```

---

# 18. STL Hash Functions

C++ already supports hashing for

```
int

long long

char

string

float

double

pointer
```

Using

```cpp
hash<int>

hash<string>
```

Example

```cpp
hash<string> h;

cout<<h("apple");
```

---

# 19. Time Complexity

| Operation | unordered_map | unordered_set |
|-----------|---------------|---------------|
| Insert | O(1) Avg |
| Search | O(1) Avg |
| Delete | O(1) Avg |
| Worst Case | O(n) |

---

# 20. Popular Interview Problems

Easy

- Two Sum
- Contains Duplicate
- Valid Anagram
- Happy Number
- Intersection of Arrays

Medium

- Group Anagrams
- Top K Frequent Elements
- Longest Consecutive Sequence
- Subarray Sum Equals K
- Isomorphic Strings

Hard

- Minimum Window Substring
- LFU Cache
- Sliding Window Maximum
- Find All Anagrams

---

# 21. Common Mistakes

## Using map instead of unordered_map

If sorting isn't required

Prefer

```cpp
unordered_map
```

---

## Using [] for searching

Wrong

```cpp
mp[5];
```

This creates the key.

Correct

```cpp
mp.find(5);
```

or

```cpp
mp.count(5);
```

---

## Forgetting collisions

Worst case

```
O(n)
```

Average

```
O(1)
```

---

## Expecting sorted output

unordered_map is unordered.

If sorted keys are needed

Use

```cpp
map
```

---

# 22. Best Practices

✅ Use unordered_map for fast lookup.

✅ Use unordered_set for presence checking.

✅ Use map only when ordering matters.

✅ Store frequency instead of repeatedly counting.

✅ Store index when searching pairs.

✅ Store prefix sums for subarray problems.

✅ Use custom hash for custom objects.

---

# 23. Summary

Hashing is one of the most powerful concepts in Data Structures and Algorithms.

Whenever you encounter a problem involving:

- Fast lookup
- Duplicate detection
- Frequency counting
- Pair finding
- Index storage
- Prefix sums
- Character counting
- Visited elements
- Membership testing

Think **Hashing first**.

### Mental Decision Tree

```
Problem
   │
   ▼
Need fast lookup?
   │
   ├── No → Consider other data structures
   │
   └── Yes
         │
         ▼
What should be stored?
         │
         ├── Value only
         │      → unordered_set
         │
         ├── Value → Count
         │      → unordered_map<Value, Count>
         │
         ├── Value → Index
         │      → unordered_map<Value, Index>
         │
         └── Prefix → Data
                → unordered_map<Prefix, Data>
```

Mastering hashing enables you to solve a large class of array, string, prefix sum, graph, and sliding window problems efficiently, making it one of the highest-return topics for coding interviews and competitive programming.