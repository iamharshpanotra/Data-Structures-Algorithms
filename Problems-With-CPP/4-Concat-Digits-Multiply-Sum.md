# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

- **Difficulty:** Easy
- **Topics:** Math, Simulation

---

# Problem

You are given an integer `n`.

- Form a new integer `x` by concatenating all the **non-zero digits** of `n` in their original order.
- Compute the sum of digits of `x`.
- Return the value of:

```text
x × (sum of digits of x)
```

If there are no non-zero digits, then `x = 0`.

---

# Intuition

While extracting digits using `% 10`, the digits are processed from **right to left**, which reverses their original order.

To preserve the original order:
1. Build a reversed number using the non-zero digits.
2. Reverse it again to obtain the required number `x`.
3. Multiply `x` by the sum of its digits.

---

# Approach

1. Initialize:
   - `reversed_x = 0`
   - `x = 0`
   - `sum = 0`
2. Traverse all digits of `n`.
3. Ignore zeros.
4. For every non-zero digit:
   - Add it to `sum`.
   - Append it to `reversed_x`.
5. Reverse `reversed_x` to obtain `x`.
6. Return `x * sum`.

---

# Algorithm

1. Set `x = 0`, `reversed_x = 0`, `sum = 0`.
2. While `n > 0`:
   - Extract the last digit.
   - If the digit is non-zero:
     - Add it to `sum`.
     - Append it to `reversed_x`.
   - Remove the last digit from `n`.
3. Reverse `reversed_x` into `x`.
4. Return `x * sum`.

---

# Code

```cpp
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long reversed_x = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit != 0) {
                sum = sum + digit;
                reversed_x = (reversed_x * 10) + digit;
            }

            n = n / 10;
        }

        while (reversed_x > 0) {
            int digit = reversed_x % 10;
            x = x * 10 + digit;
            reversed_x = reversed_x / 10;
        }

        return x * sum;
    }
};
```

---

# Dry Run

### Input

```text
n = 10203004
```

### First Loop

| Digit | Non-Zero? | reversed_x | sum |
|------:|:---------:|-----------:|----:|
| 4 | Yes | 4 | 4 |
| 0 | No | 4 | 4 |
| 0 | No | 4 | 4 |
| 3 | Yes | 43 | 7 |
| 0 | No | 43 | 7 |
| 2 | Yes | 432 | 9 |
| 0 | No | 432 | 9 |
| 1 | Yes | 4321 | 10 |

After first loop:

```text
reversed_x = 4321
sum = 10
```

### Second Loop

| Digit | x |
|------:|--:|
| 1 | 1 |
| 2 | 12 |
| 3 | 123 |
| 4 | 1234 |

Final:

```text
x = 1234
sum = 10

Answer = 1234 × 10 = 12340
```

---

# Complexity

- **Time Complexity:** `O(d)`
- **Space Complexity:** `O(1)`

Where `d` is the number of digits in `n`.

---

# Key Points

- Digits extracted using `% 10` are processed from right to left.
- A second reversal restores the original digit order.
- Zero digits are skipped completely.
- Only constant extra space is used.

---

# Pattern Recognition

- Digit Manipulation
- Number Reversal
- Simulation
- Math

---

# Related Problems

- Two Sum
- Palindrome Number
- Reverse Integer
- Plus One
- Add Digits
- Count Digits