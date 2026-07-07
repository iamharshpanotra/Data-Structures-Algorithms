# Contains Duplicate (LeetCode 217)

## Problem

Given an integer array `nums`, return `true` if any value appears at least twice; otherwise, return `false`.

---

## Approach

Use an `unordered_set` to store visited elements.

- Traverse the array once.
- If the current element already exists in the set, return `true`.
- Otherwise, insert it into the set.
- If traversal completes, return `false`.

---

## Algorithm

1. Create an empty `unordered_set<int>`.
2. Iterate through the array.
3. Check if the current element exists in the set.
   - Yes → return `true`.
   - No → insert it.
4. Return `false`.

---

## Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num))
                return true;

            seen.insert(num);
        }

        return false;
    }
};
```

---

## Dry Run

Input:

```cpp
nums = [1,2,3,1]
```

| Element | Set | Action |
|---------|-----|--------|
| 1 | {} | Insert |
| 2 | {1} | Insert |
| 3 | {1,2} | Insert |
| 1 | {1,2,3} | Duplicate Found → Return `true` |

---

## Complexity

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(n)** |

---

## Why `unordered_set`?

- Average lookup: **O(1)**
- Average insertion: **O(1)**
- Stores only unique elements
- Ideal for duplicate detection

---

## Key Points

- Check before inserting.
- Return immediately when a duplicate is found.
- `count()` returns `1` if the element exists; otherwise `0`.
- Best solution using hashing.

---

## Pattern Recognition

Use a hash-based data structure when the problem involves:

- Duplicates
- Distinct elements
- "Seen before"
- Membership checking
- Fast lookup

Preferred choices:

- `unordered_set`
- `unordered_map`

---

## Takeaway

Hashing reduces the brute-force solution from **O(n²)** to **O(n)** by enabling constant-time average lookups.




#########################################################


# Contains Duplicate (LeetCode 217)

# Difficulty
**Easy**

---

# Problem Statement

Given an integer array `nums`, return:

- `true` if any value appears **at least twice** in the array.
- `false` if every element is **unique**.

### Example 1

```cpp
Input: nums = [1,2,3,1]

Output: true
```

Explanation:

```
1 appears twice.
```

---

### Example 2

```cpp
Input: nums = [1,2,3,4]

Output: false
```

Explanation:

```
Every element is unique.
```

---

### Example 3

```cpp
Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true
```

---

# Understanding the Problem

The question is actually asking:

> "Has this number already appeared before?"

If yes → Return `true`

If no → Continue checking.

The moment we find the same number again, we don't need to continue.

---

# Brute Force Approach

Compare every element with every other element.

```cpp
for(i = 0; i < n; i++)
{
    for(j = i + 1; j < n; j++)
    {
        if(nums[i] == nums[j])
            return true;
    }
}

return false;
```

## Time Complexity

```
O(n²)
```

Because every element is compared with almost every other element.

## Space Complexity

```
O(1)
```

No extra memory.

---

# Better Approach (Hashing)

Instead of comparing every element,

Store every visited number inside a Hash Set.

Whenever a new number comes,

Ask:

> "Have I already seen this?"

If yes,

Return `true`.

Otherwise,

Store it.

---

# Data Structure Used

```cpp
unordered_set<int>
```

Think of it as a bag containing unique elements.

Example

```
Bag

{}

Insert 5

{5}

Insert 2

{5,2}

Insert 8

{5,2,8}

Insert 2 again

Already exists!
```

Duplicate found.

---

# Visual Dry Run

Input

```cpp
nums = [1,2,3,1]
```

Initially

```
Bag = {}
```

---

## Iteration 1

Current number

```
1
```

Check

```
Bag contains 1?

No
```

Insert

```
Bag = {1}
```

---

## Iteration 2

Current number

```
2
```

Check

```
Bag contains 2?

No
```

Insert

```
Bag = {1,2}
```

---

## Iteration 3

Current number

```
3
```

Check

```
Bag contains 3?

No
```

Insert

```
Bag = {1,2,3}
```

---

## Iteration 4

Current number

```
1
```

Check

```
Bag contains 1?

YES
```

Return

```cpp
true
```

No need to continue.

---

# Complete Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> bag;

        for (int i = 0; i < nums.size(); i++) {

            if (bag.count(nums[i]) > 0) {
                return true;
            }

            bag.insert(nums[i]);
        }

        return false;
    }
};
```

---

# Line-by-Line Explanation

---

## Function Header

```cpp
bool containsDuplicate(vector<int>& nums)
```

- Returns a boolean.
- Takes the array by reference.
- No unnecessary copying.

---

## Create Hash Set

```cpp
unordered_set<int> bag;
```

Initially

```
{}
```

The set stores only unique values.

---

## Loop through every element

```cpp
for(int i = 0; i < nums.size(); i++)
```

Visit every number once.

---

## Check if already exists

```cpp
if(bag.count(nums[i]) > 0)
```

`count()` returns

```
1 → Exists

0 → Doesn't exist
```

Example

```
Bag = {5,7,9}

bag.count(7)

Returns 1

bag.count(2)

Returns 0
```

---

## Duplicate Found

```cpp
return true;
```

As soon as we find a duplicate,

No further work is needed.

---

## Store Current Number

```cpp
bag.insert(nums[i]);
```

Example

Before

```
{1,2}
```

Insert

```
3
```

After

```
{1,2,3}
```

---

## No Duplicate Found

After loop finishes,

```cpp
return false;
```

Meaning

Every element was unique.

---

# Why Check Before Insert?

Correct Order

```cpp
if(bag.count(nums[i]))
    return true;

bag.insert(nums[i]);
```

Suppose

```
Bag = {}

Current = 5
```

Check first

```
Exists?

No
```

Insert

```
{5}
```

Next time

```
Current = 5

Exists?

Yes
```

Duplicate found.

---

Wrong Order

```cpp
bag.insert(nums[i]);

if(bag.count(nums[i]))
```

First element itself becomes

```
Insert 5

Bag = {5}

Check

Exists?

Yes
```

It would incorrectly return `true` immediately.

Always:

```
CHECK

↓

INSERT
```

---

# Understanding `unordered_set`

Properties

- Stores only unique elements.
- Average lookup is very fast.
- Average insertion is very fast.
- Duplicate insertions are ignored.

Example

```cpp
unordered_set<int> bag;

bag.insert(5);
bag.insert(2);
bag.insert(5);
```

Result

```
{5,2}
```

Only one `5` exists.

---

# Why `unordered_set` is Perfect Here

We only need to answer one question:

```
Have I seen this number before?
```

Operations

```
Insert

Search

Exists?
```

All are approximately

```
O(1)
```

---

# Time Complexity

Loop

```
O(n)
```

Each lookup

```
O(1)
```

Each insertion

```
O(1)
```

Overall

```
O(n)
```

---

# Space Complexity

Worst case

Every number is unique.

Example

```
[1,2,3,4,5]
```

Set stores all numbers.

```
O(n)
```

---

# Comparison

| Approach | Time | Space |
|----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Hash Set | O(n) | O(n) |

---

# Pattern Recognition

Whenever the problem says:

- Duplicate
- Repeated element
- Seen before
- Unique elements
- Distinct values
- Frequency
- Find if already exists

Think immediately:

```
Hashing
```

Usually

```
unordered_set

or

unordered_map
```

---

# Interview Explanation

> I use an `unordered_set` to keep track of numbers that have already been seen. As I iterate through the array, I first check whether the current number already exists in the set using `count()`. If it does, I immediately return `true` because a duplicate has been found. Otherwise, I insert the current number into the set and continue. If the loop finishes without finding any duplicates, I return `false`. This solution runs in **O(n)** average time with **O(n)** extra space.

---

# Key Takeaways

- Use a hash set when checking whether an element has been seen before.
- Always **check first, then insert**.
- `unordered_set` stores only unique values.
- `count()` returns `1` if the element exists, otherwise `0`.
- This reduces the time complexity from **O(n²)** to **O(n)**.
- Duplicate-related problems are strong indicators that **hashing** is the right approach.

---

# Final Code

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> bag;

        for (int i = 0; i < nums.size(); i++) {

            if (bag.count(nums[i]) > 0) {
                return true;
            }

            bag.insert(nums[i]);
        }

        return false;
    }
};
```

**Time Complexity:** `O(n)` (average case)  
**Space Complexity:** `O(n)`