# 349. Intersection of Two Arrays

## Problem Statement

Given two integer arrays `nums1` and `nums2`, return an array containing their **intersection**.

### Rules

* Each element in the result must be **unique**.
* The order of elements in the result does **not matter**.

---

## Examples

### Example 1

```text
Input:
nums1 = [1,2,2,1]
nums2 = [2,2]

Output:
[2]
```

### Example 2

```text
Input:
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]

Output:
[9,4]
```

---

# Intuition

We need only the **unique common elements** between both arrays.

A hash-based data structure is ideal because it provides **O(1)** average lookup time. We can store all unique elements from `nums1` inside a hash set and then check whether elements of `nums2` exist in that set.

---

# Approach

1. Insert all elements of `nums1` into an `unordered_set`.

   * Duplicate values are automatically removed.

2. Traverse `nums2`.

   * If the current element exists in the set:

     * Add it to the result.
     * Remove it from the set to avoid duplicates in the answer.

---

# Algorithm

```text
1. Create a hash set from nums1.
2. Initialize an empty result vector.
3. Iterate through nums2:
      a. If current element exists in set:
             Add it to result.
             Remove it from set.
4. Return result.
```

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1,
                             vector<int>& nums2) {

        unordered_set<int> bag(nums1.begin(),
                               nums1.end());

        vector<int> result;

        for (int i = 0; i < nums2.size(); i++) {
            int current_num = nums2[i];

            if (bag.count(current_num) > 0) {
                result.push_back(current_num);

                // Prevent duplicates
                bag.erase(current_num);
            }
        }

        return result;
    }
};
```

---

# Dry Run

### Input

```text
nums1 = [1,2,2,1]
nums2 = [2,2]
```

### Initial State

```text
bag = {1,2}
result = []
```

| Step | Current Number | Exists in Set? | Action       | Result | Set |
| ---- | -------------- | -------------- | ------------ | ------ | --- |
| 1    | 2              | Yes            | Add & Remove | [2]    | {1} |
| 2    | 2              | No             | Skip         | [2]    | {1} |

### Final Output

```text
[2]
```

---

# Complexity Analysis

| Operation         | Complexity   |
| ----------------- | ------------ |
| Building Hash Set | O(n)         |
| Traversing nums2  | O(m)         |
| Total Time        | **O(n + m)** |
| Auxiliary Space   | **O(n)**     |

Where:

* `n = nums1.size()`
* `m = nums2.size()`

---

# Key Points

* `unordered_set` automatically stores only unique values.
* `count(value)` checks whether an element exists.
* `erase(value)` ensures duplicates are not inserted into the result.
* This solution is more efficient than a brute-force nested loop approach (`O(n × m)`).

---

# Pattern Recognition

### Pattern Used:

✅ **Hashing / Hash Set**

### When to Think About This Pattern

Use a hash set whenever a problem involves:

* Fast existence checking
* Duplicate removal
* Unique element tracking
* Intersection or union of arrays

---

# Similar Problems

1. **217. Contains Duplicate**
2. **242. Valid Anagram**
3. **350. Intersection of Two Arrays II**
4. **349. Intersection of Two Arrays**
5. **128. Longest Consecutive Sequence**

---

```
```

# Interview Takeaway

The key observation is that the problem only requires **unique common elements**, making `unordered_set` the ideal data structure.

Hashing reduces the solution from **O(n × m)** to **O(n + m)** while keeping the implementation simple and clean.
