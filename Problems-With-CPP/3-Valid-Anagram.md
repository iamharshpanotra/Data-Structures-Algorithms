# 242. Valid Anagram

**Difficulty:** Easy  
**Pattern:** Hashing, Frequency Counting, String

---

# Problem

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

An **anagram** is a word or phrase formed by rearranging the letters of another word using all the original characters exactly once.

### Example 1

```text
Input:
s = "anagram"
t = "nagaram"

Output:
true
```

### Example 2

```text
Input:
s = "rat"
t = "car"

Output:
false
```

---

# Intuition

If two strings are anagrams, every character must appear the same number of times in both strings. We use a hash map to count character frequencies in the first string and decrease them while traversing the second string.

---

# Approach

- Compare the lengths of both strings.
- If they differ, return `false`.
- Store the frequency of every character from `s` in an `unordered_map`.
- Traverse `t`:
  - If a character is not present or its frequency is already `0`, return `false`.
  - Otherwise, decrement its frequency.
- If all characters are processed successfully, return `true`.

---

# Algorithm

1. Check whether the lengths of `s` and `t` are equal.
2. If not, return `false`.
3. Create an `unordered_map<char, int>` to store character frequencies.
4. Traverse `s` and increment the count of each character.
5. Traverse `t`:
   - If the character's count is `0`, return `false`.
   - Otherwise, decrement its count.
6. After processing all characters, return `true`.

---

# Code (C++)

```cpp
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {

        // Step 1: Check if the lengths are different
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> counts;

        // Step 2: Count frequencies of characters in string s
        for (char c : s) {
            counts[c]++;
        }

        // Step 3: Decrement frequencies using string t
        for (char c : t) {

            // Character not found or frequency exhausted
            if (counts[c] == 0) {
                return false;
            }

            counts[c]--;
        }

        // Step 4: All characters matched
        return true;
    }
};
```

---

# Dry Run

### Input

```text
s = "anagram"
t = "nagaram"
```

### Step 1: Count Characters from `s`

| Character | Frequency |
|-----------|----------:|
| a | 3 |
| n | 1 |
| g | 1 |
| r | 1 |
| m | 1 |

---

### Step 2: Process Characters from `t`

| Character | Frequency Before | Frequency After |
|-----------|-----------------:|----------------:|
| n | 1 | 0 |
| a | 3 | 2 |
| g | 1 | 0 |
| a | 2 | 1 |
| r | 1 | 0 |
| a | 1 | 0 |
| m | 1 | 0 |

All frequencies are successfully reduced without encountering a negative or missing count.

**Output:** `true`

---

# Complexity

| Complexity | Value |
|------------|-------|
| **Time** | **O(n)** |
| **Space** | **O(k)** |

> **k** = Number of unique characters stored in the hash map.  
> For lowercase English letters, `k ≤ 26`, making the space effectively constant.

---

# Key Points

- Always compare string lengths first.
- `unordered_map` stores the frequency of each character.
- Return `false` immediately if a character is missing or overused.
- No sorting is required, making the solution linear in time.
- Works for any character set, not just lowercase English letters.

---

# Pattern Recognition

- Hashing
- Frequency Counting
- String Processing
- Unordered Map

---

# Related Problems

- **217.** Contains Duplicate
- **1.** Two Sum
- **49.** Group Anagrams
- **383.** Ransom Note
- **387.** First Unique Character in a String

