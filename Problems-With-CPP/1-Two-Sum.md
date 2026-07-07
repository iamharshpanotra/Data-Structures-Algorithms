# Two Sum

**Difficulty:** Easy  
**Pattern:** Hash Map

---

# Problem

Given an integer array `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

You may assume:
- Exactly one valid solution exists.
- You cannot use the same element twice.
- Return the indices in any order.

---

# Intuition

For every number, we need another number that completes the target.

Instead of searching the entire array every time, store previously visited numbers in a hash map. This allows finding the required complement in **O(1)** time.

---

# Approach

- Create a hash map to store:
  - **Key** → Number
  - **Value** → Index
- Traverse the array once.
- Calculate the required complement.

```cpp
complement = target - nums[i];
```

- If the complement already exists in the map:
  - Return its index and the current index.
- Otherwise, store the current number and its index in the map.

---

# Algorithm

1. Initialize an empty hash map.
2. Traverse the array.
3. Compute the complement.
4. Check whether the complement exists in the map.
5. If found, return both indices.
6. Otherwise, insert the current element into the map.
7. Continue until the solution is found.

---

# Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }

            map[nums[i]] = i;
        }

        return {};
    }
};
```

---

# Dry Run

### Input

```text
nums = [2, 7, 11, 15]
target = 9
```

| i | nums[i] | Complement | Hash Map Before | Found? | Action |
|---|---------|------------|-----------------|--------|--------|
| 0 | 2 | 7 | {} | No | Store {2 → 0} |
| 1 | 7 | 2 | {2 → 0} | Yes | Return {0,1} |

### Output

```text
[0,1]
```

---

# Complexity

| Metric | Complexity |
|---------|------------|
| Time | **O(n)** |
| Space | **O(n)** |

---

# Key Points

- Uses a **Hash Map** for constant-time lookup.
- Traverses the array only once.
- Avoids nested loops.
- Stores numbers already visited.
- The complement is searched before inserting the current element.
- Optimal solution for the problem.

---

# Pattern Recognition

**Pattern:** Hash Map / Lookup Table

### Identification Clues

- Find two elements satisfying a condition.
- Need fast lookup.
- Repeated searching in an array.
- Asked for an optimal solution.
- Pair sum problems.

---

# Related Problems

- Two Sum II (Sorted Array)
- Three Sum
- Four Sum
- Contains Duplicate
- Contains Duplicate II
- Intersection of Two Arrays
- Happy Number
- Group Anagrams