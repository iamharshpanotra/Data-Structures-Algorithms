# C++ Maps -- Complete Guide

## Table of Contents

1.  Introduction
2.  Types of Maps
3.  Internal Working
4.  Declaration
5.  Initialization
6.  Inserting Elements
7.  Accessing Elements
8.  Updating Values
9.  Removing Elements
10. Traversing Maps
11. Iterators
12. Important Member Functions
13. Ordered vs Unordered Map
14. Multimap
15. Custom Comparators
16. Passing Maps to Functions
17. STL Algorithms
18. Time & Space Complexity
19. Common DSA Patterns
20. Common Mistakes
21. Best Practices
22. Cheat Sheet

------------------------------------------------------------------------

# 1. Introduction

A **map** is an STL associative container that stores **key-value
pairs**.

``` cpp
map<string,int> age;
```

Example:

``` text
Key      Value
Alice -> 24
Bob   -> 30
John  -> 18
```

Keys are unique.

------------------------------------------------------------------------

# 2. Types of Maps

``` cpp
map<Key,Value>
unordered_map<Key,Value>
multimap<Key,Value>
```

-   `map` → Sorted by key (Red-Black Tree)
-   `unordered_map` → Hash Table
-   `multimap` → Duplicate keys allowed

------------------------------------------------------------------------

# 3. Internal Working

## map

-   Self-balancing Red-Black Tree
-   Keys remain sorted

## unordered_map

-   Hash Table
-   No ordering
-   Average O(1) lookup

------------------------------------------------------------------------

# 4. Declaration

``` cpp
#include <map>
#include <unordered_map>

map<int,string> m;
unordered_map<int,string> um;
```

------------------------------------------------------------------------

# 5. Initialization

``` cpp
map<int,string> m={
    {1,"One"},
    {2,"Two"},
    {3,"Three"}
};
```

------------------------------------------------------------------------

# 6. Inserting Elements

``` cpp
m[1]="One";
m.insert({2,"Two"});
m.emplace(3,"Three");
```

------------------------------------------------------------------------

# 7. Accessing Elements

``` cpp
cout<<m[1];
cout<<m.at(2);
```

Check existence

``` cpp
if(m.find(3)!=m.end())
    cout<<"Found";
```

``` cpp
if(m.count(3))
    cout<<"Exists";
```

------------------------------------------------------------------------

# 8. Updating Values

``` cpp
m[2]="Updated";
```

------------------------------------------------------------------------

# 9. Removing Elements

``` cpp
m.erase(2);
m.clear();
```

------------------------------------------------------------------------

# 10. Traversing

Range loop

``` cpp
for(auto &p:m)
    cout<<p.first<<" "<<p.second<<"\n";
```

Iterator

``` cpp
for(auto it=m.begin();it!=m.end();++it)
    cout<<it->first<<" "<<it->second;
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

# 12. Important Functions

``` cpp
insert()
emplace()
erase()
clear()
find()
count()
size()
empty()
lower_bound()
upper_bound()
equal_range()
swap()
```

------------------------------------------------------------------------

# 13. Ordered vs Unordered Map

  Feature      map              unordered_map
  ------------ ---------------- ---------------
  Structure    Red-Black Tree   Hash Table
  Order        Sorted           Unordered
  Search       O(log n)         O(1) average
  Insert       O(log n)         O(1) average
  Worst Case   O(log n)         O(n)

Use `map` when sorted keys are needed; otherwise prefer `unordered_map`
for speed.

------------------------------------------------------------------------

# 14. Multimap

Allows duplicate keys.

``` cpp
multimap<int,string> mm;

mm.insert({1,"A"});
mm.insert({1,"B"});
```

Retrieve duplicates:

``` cpp
auto range=mm.equal_range(1);
for(auto it=range.first;it!=range.second;++it)
    cout<<it->second;
```

------------------------------------------------------------------------

# 15. Custom Comparator

Descending order:

``` cpp
map<int,string,greater<int>> m;
```

------------------------------------------------------------------------

# 16. Passing Maps

``` cpp
void print(const map<int,string>& m)
{
    for(auto &p:m)
        cout<<p.first<<" "<<p.second;
}
```

------------------------------------------------------------------------

# 17. STL-Friendly Operations

Maximum frequency:

``` cpp
unordered_map<int,int> freq;

for(int x:nums)
    freq[x]++;
```

Word frequency:

``` cpp
unordered_map<string,int> words;
```

------------------------------------------------------------------------

# 18. Time & Space Complexity

## map

  Operation   Complexity
  ----------- ------------
  Insert      O(log n)
  Search      O(log n)
  Erase       O(log n)
  Traversal   O(n)

## unordered_map

  Operation     Average   Worst
  ----------- --------- -------
  Insert           O(1)    O(n)
  Search           O(1)    O(n)
  Erase            O(1)    O(n)

Space: **O(n)**

------------------------------------------------------------------------

# 19. Common DSA Patterns

-   Frequency counting
-   Two Sum
-   Group Anagrams
-   First Unique Character
-   Top K Frequent Elements
-   Counting occurrences
-   Prefix sums with hash map
-   Sliding window
-   Caching
-   Memoization

------------------------------------------------------------------------

# 20. Common Mistakes

-   Using `m[key]` only to check existence (creates a new key).
-   Assuming `unordered_map` is ordered.
-   Forgetting duplicate keys are not allowed in `map`.
-   Modifying a map while iterating incorrectly.
-   Ignoring worst-case complexity of `unordered_map`.

------------------------------------------------------------------------

# 21. Best Practices

-   Use `unordered_map` unless sorted order is required.
-   Use `find()` instead of `operator[]` for existence checks.
-   Pass maps by `const&`.
-   Prefer `emplace()` over `insert()` when constructing values.
-   Reserve buckets for very large `unordered_map`s if needed.

------------------------------------------------------------------------

# 22. Cheat Sheet

``` cpp
map<int,string> m;

m[1]="One";

m.insert({2,"Two"});
m.emplace(3,"Three");

m.find(2);

m.count(2);

m.erase(2);

for(auto &p:m)
    cout<<p.first<<" "<<p.second;

unordered_map<int,int> freq;

freq[x]++;

multimap<int,string> mm;

mm.equal_range(1);
```

------------------------------------------------------------------------

# Summary

Maps are one of the most important STL containers in C++. They
efficiently associate keys with values and are heavily used in
competitive programming and interviews. Master `map`, `unordered_map`,
and `multimap`, understand their complexities, and know when each is
appropriate.
