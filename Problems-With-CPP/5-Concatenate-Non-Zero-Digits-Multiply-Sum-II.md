# 3756. Concatenate Non-Zero Digits and Multiply by Sum II

**Difficulty:** Medium  
**Topics:** Prefix Sum, String, Math, Modular Arithmetic, Preprocessing

---

# Problem

You are given:

- A string `s` consisting of digits.
- A list of queries `[l, r]`.

For every query:

1. Extract the substring `s[l...r]`.
2. Remove all `0`s while preserving the order of remaining digits.
3. Concatenate the remaining digits to form an integer `x`.
4. Compute the sum of digits of `x`.
5. Return `x × sum` modulo **1e9 + 7**.

---

# Intuition

A brute-force solution would rebuild the number for every query, resulting in **O(N × Q)** complexity, which is too slow for `10^5` queries.

Instead, preprocess the string once using prefix arrays so each query can be answered in **O(1)** time.

---

# Approach

We preprocess three prefix arrays:

### 1. Prefix Digit Sum (`pref_sum`)

Stores the cumulative sum of all digits.

```
pref_sum[i]
```

Allows us to calculate the digit sum of any substring in O(1).

---

### 2. Prefix Non-Zero Number (`pref_x`)

Builds the integer formed by concatenating only non-zero digits.

Example:

```
String : 1020304

pref_x builds:

1
12
123
1234
```

Each non-zero digit is appended using:

```
pref_x = pref_x × 10 + digit
```

All calculations are performed modulo **1e9+7**.

---

### 3. Prefix Non-Zero Count (`new_count`)

Stores how many non-zero digits have appeared so far.

This helps determine how many digits belong to a query.

---

### Power of 10

Precompute:

```
10^0
10^1
10^2
...
10^N
```

This allows removing the prefix contribution efficiently.

---

# Algorithm

1. Precompute powers of 10 modulo `1e9+7`.
2. Build:
   - `pref_sum`
   - `pref_x`
   - `new_count`
3. For every query:
   - Find the number of non-zero digits.
   - Compute the digit sum.
   - Remove the prefix contribution from `pref_x`.
   - Multiply the resulting value with the digit sum.
   - Return modulo `1e9+7`.

---

# Code

```cpp
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long M = 1000000007;

        vector<long long> power10(n + 1, 1);

        // Precompute powers of 10
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % M;
        }

        // Prefix arrays
        vector<long long> pref_sum(n + 1, 0);
        vector<long long> pref_x(n + 1, 0);
        vector<int> new_count(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            pref_sum[i + 1] = pref_sum[i] + digit;

            if (digit != 0) {
                pref_x[i + 1] = (pref_x[i] * 10 + digit) % M;
                new_count[i + 1] = new_count[i] + 1;
            } else {
                pref_x[i + 1] = pref_x[i];
                new_count[i + 1] = new_count[i];
            }
        }

        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            int k = new_count[r + 1] - new_count[l];

            long long sum_val = pref_sum[r + 1] - pref_sum[l];

            long long value =
                (pref_x[r + 1] -
                 (pref_x[l] * power10[k]) % M +
                 M) % M;

            ans.push_back((value * sum_val) % M);
        }

        return ans;
    }
};
```

---

# Dry Run

### Input

```
s = "10203004"

Query = [0,7]
```

### Prefix Arrays

| Index | Digit | pref_sum | pref_x | new_count |
|------:|------:|---------:|-------:|----------:|
|0|1|1|1|1|
|1|0|1|1|1|
|2|2|3|12|2|
|3|0|3|12|2|
|4|3|6|123|3|
|5|0|6|123|3|
|6|0|6|123|3|
|7|4|10|1234|4|

For query:

```
k = 4
sum = 10
value = 1234

Answer = 1234 × 10 = 12340
```

---

# Complexity

| Operation | Complexity |
|-----------|------------|
|Preprocessing|O(N)|
|Each Query|O(1)|
|Total Queries|O(Q)|
|Overall|O(N + Q)|

### Space Complexity

```
O(N)
```

Used for prefix arrays and powers of 10.

---

# Key Points

- Precompute everything once.
- Prefix sums provide digit sums in O(1).
- Prefix concatenation avoids rebuilding numbers.
- Prefix non-zero count determines digit length.
- Powers of 10 remove unwanted prefix digits.
- All arithmetic is performed modulo **1e9+7**.

---

# Pattern Recognition

This problem combines several common DSA patterns:

- Prefix Sum
- Prefix Preprocessing
- Modular Arithmetic
- String Processing
- Range Query
- Mathematical Construction

---

# Related Problems

- **303. Range Sum Query – Immutable**
- **238. Product of Array Except Self**
- **304. Range Sum Query 2D – Immutable**
- **560. Subarray Sum Equals K**
- **974. Subarray Sums Divisible by K**
- **3754. Concatenate Non-Zero Digits and Multiply by Sum I**
```