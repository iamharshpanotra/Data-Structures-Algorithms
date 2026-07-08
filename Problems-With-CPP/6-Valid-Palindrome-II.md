# 680. Valid Palindrome II

* **Difficulty:** Easy
* **Topics:** Two Pointers, String
* **Companies:** Frequently Asked in Interviews

---

# Problem Statement

Given a string `s`, return **true** if the string can become a palindrome after deleting **at most one character**. Otherwise, return **false**.

A palindrome is a string that reads the same forward and backward.

---

# Examples

### Example 1

```text
Input: s = "aba"
Output: true
```

**Explanation:**

The string is already a palindrome.

---

### Example 2

```text
Input: s = "abca"
Output: true
```

**Explanation:**

Delete `'c'` to obtain `"aba"`.

---

### Example 3

```text
Input: s = "abc"
Output: false
```

**Explanation:**

Removing one character cannot make the string a palindrome.

---

# Constraints

```text
1 <= s.length <= 10^5
s consists of lowercase English letters.
```

---

# Intuition

A palindrome can be verified using two pointers.

* Compare characters from both ends.
* If they match, continue moving inward.
* At the first mismatch, we have only one deletion available.
* Try skipping either the left character or the right character.
* If either remaining substring is a palindrome, the answer is `true`.

---

# Approach

1. Initialize two pointers:

   * `left = 0`
   * `right = n - 1`
2. Compare characters at both pointers.
3. If they match, move both pointers inward.
4. On the first mismatch:

   * Check whether removing the left character forms a palindrome.
   * Check whether removing the right character forms a palindrome.
5. Return `true` if either check succeeds.
6. If the entire string is traversed without issues, return `true`.

---

# Algorithm

1. Set `left = 0` and `right = n - 1`.
2. While `left < right`:

   * If characters are equal:

     * Increment `left`.
     * Decrement `right`.
   * Otherwise:

     * Return:

       * `isPalindrome(left + 1, right)` OR
       * `isPalindrome(left, right - 1)`
3. If the loop completes, return `true`.

---

# Code (C++)

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                return isPalindrome(s, left + 1, right) ||
                       isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }

    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
```

---

# Dry Run

### Input

```text
s = "abca"
```

| Step  | Left       | Right       | Characters | Action                     |
| ----- | ---------- | ----------- | ---------- | -------------------------- |
| 1     | 0          | 3           | a == a     | Move both pointers         |
| 2     | 1          | 2           | b != c     | Try deleting one character |
| 3     | Skip `'b'` | Check `"c"` | Palindrome | False                      |
| 4     | Skip `'c'` | Check `"b"` | Palindrome | True                       |
| Final | -          | -           | -          | Return **true**            |

---

# Complexity Analysis

### Time Complexity

* Main traversal: **O(n)**
* Palindrome verification after one mismatch: **O(n)**

**Overall:** `O(n)`

---

### Space Complexity

No extra data structures are used.

**Space:** `O(1)`

---

# Why Does This Work?

The first mismatch is the only place where a deletion can help.

There are only two possible choices:

* Delete the left mismatched character.
* Delete the right mismatched character.

If neither resulting substring is a palindrome, no other deletion can make the original string valid.

---

# Key Points

* Uses the **Two Pointer** technique.
* Only **one mismatch** requires additional checking.
* Helper function verifies whether a substring is a palindrome.
* No extra memory is required.
* Efficient enough for strings up to `10^5` characters.

---

# Pattern Recognition

* ✅ Two Pointers
* ✅ Greedy Decision
* ✅ Palindrome Validation
* ✅ String Processing

---

# Similar Problems

* 125. Valid Palindrome
* 9. Palindrome Number
* 647. Palindromic Substrings
* 5. Longest Palindromic Substring
* 131. Palindrome Partitioning

---

# Interview Tips

* A brute-force solution tries deleting every character and checks for a palindrome, resulting in **O(n²)** time.
* The optimal solution uses **Two Pointers** and performs at most **one additional palindrome check**, reducing the complexity to **O(n)**.
* This is a classic interview problem that tests your understanding of **Two Pointers**, **Greedy reasoning**, and **efficient string traversal**.
