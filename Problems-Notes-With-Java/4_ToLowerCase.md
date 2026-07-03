This problem is a classic introduction to how computers represent text under the hood. While you could easily call `s.toLowerCase()` in Java, the real "study value" here is understanding the **ASCII table** and bit manipulation.

### 💡 The Core Concept: ASCII Values

In the ASCII system, every character has a numerical value.

* **'A'** is **65**
* **'B'** is **66**
* ...
* **'Z'** is **90**

Lowercase letters follow the same pattern but start later:

* **'a'** is **97**
* **'b'** is **98**
* ...
* **'z'** is **122**

The "magic" number here is **32**. The difference between any uppercase letter and its lowercase counterpart is exactly 32 ().

---

### 🛠️ The Strategy: Manual Conversion

1. **Convert** the string to a `char[]`.
2. **Iterate** through each character.
3. **Check** if the character is "Upper Case" (i.e., its value is between 'A' and 'Z').
4. **Transform**: If it is uppercase, add 32 to its integer value to turn it into lowercase.
5. **Ignore**: If it's already lowercase or a symbol (like `@` or `!`), leave it alone.

---

### 💻 Java Implementation

Here is the `.md` summary of the implementation:

```markdown
# Study Note: To Lower Case

## 📌 Problem Description
Given a string `s`, return the string after replacing every uppercase letter with the same lowercase letter without using built-in library functions.

---

## 🛠️ The Strategy: ASCII Manipulation
Every character in Java is essentially a 16-bit integer. We can perform math on characters to shift them from the "Uppercase Range" to the "Lowercase Range."

### Steps:
1.  **Convert** to a `char[]`.
2.  **Loop** through the array.
3.  **Range Check**: If a character `c >= 'A'` and `c <= 'Z'`.
4.  **Shift**: Add 32 to the character. In Java, this looks like `c += 32` or `c = (char)(c + 32)`.

---

## 💻 Java Implementation

```java
class Solution {
    public String toLowerCase(String s) {
        char[] chars = s.toCharArray();
        
        for (int i = 0; i < chars.length; i++) {
            // Check if the character is within the Uppercase ASCII range (65-90)
            if (chars[i] >= 'A' && chars[i] <= 'Z') {
                // Shift by 32 to reach the Lowercase range (97-122)
                chars[i] = (char) (chars[i] + 32);
            }
        }
        
        return new String(chars);
    }
}

```

---

## 🧠 Complexity Analysis

### Time Complexity: 

We visit each character in the string exactly once.

### Space Complexity: 

We create a character array of size  to store and modify the result.

---

## ⚡ Pro-Tip: Bitwise Logic

Interestingly, the difference of 32 is exactly . In binary, this means the only difference between 'A' and 'a' is a single bit.

* Uppercase letters have the 6th bit as `0`.
* Lowercase letters have the 6th bit as `1`.
You can actually convert to lowercase using the OR bitwise operator: `chars[i] |= 32;`

```

Since we've looked at modifying characters using math, would you like to see how **Bitwise operators** (like `|` or `&`) can do this even faster?

```