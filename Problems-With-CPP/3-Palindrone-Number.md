# Palindrome Number

## Problem

Given an integer `x`, return `true` if `x` is a palindrome, otherwise return `false`.

A palindrome number reads the same forward and backward.

### Example

```text
Input: x = 121
Output: true

Input: x = -121
Output: false

Input: x = 10
Output: false
```

---

## Intuition

A palindrome number remains the same when its digits are reversed. Reverse the number and compare it with the original value.

---

## Approach

1. Return `false` if the number is negative.
2. Store the original number.
3. Reverse the digits using modulo (`%`) and division (`/`).
4. Compare the reversed number with the original.
5. Return the comparison result.

---

## Algorithm

1. If `x < 0`, return `false`.
2. Store `original = x`.
3. Initialize `reverse = 0`.
4. While `x > 0`:
   - Extract the last digit.
   - Append it to `reverse`.
   - Remove the last digit from `x`.
5. Return `reverse == original`.

---

## Code (C++)

```cpp
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        long long reverse = 0;
        int original = x;

        while (x > 0) {
            int digit = x % 10;
            reverse = reverse * 10 + digit;
            x /= 10;
        }

        return reverse == original;
    }
};
```

---

## Dry Run

### Input: `121`

| Step | x | Digit | Reverse |
|------|---:|------:|--------:|
| Start | 121 | - | 0 |
| 1 | 121 | 1 | 1 |
| 2 | 12 | 2 | 12 |
| 3 | 1 | 1 | 121 |
| End | 0 | - | 121 |

**Result:** `121 == 121` → `true`

---

### Input: `10`

| Step | x | Digit | Reverse |
|------|---:|------:|--------:|
| Start | 10 | - | 0 |
| 1 | 10 | 0 | 0 |
| 2 | 1 | 1 | 1 |
| End | 0 | - | 1 |

**Result:** `1 != 10` → `false`

---

## Complexity

- **Time Complexity:** `O(log₁₀ n)`
- **Space Complexity:** `O(1)`

---

## Key Points

- Negative numbers are never palindromes.
- Reverse the number digit by digit.
- Use `long long` to avoid overflow while reversing.
- Compare the reversed value with the original number.

---

## Pattern Recognition

- **Pattern:** Number Manipulation
- **Technique:** Reverse Digits
- **Data Structure:** None

---

## Related Problems

- Reverse Integer
- Plus One
- Happy Number
- Valid Palindrome