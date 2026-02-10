This problem is all about efficient navigation. While you could use `s.split(" ")` to break the string into an array and grab the last element, that's like using a sledgehammer to crack a nut—it uses extra memory () to store all the other words we don't actually care about.

The most optimized way to solve this is to **work backward**.

### 💡 The Strategy: Reverse Traversal

Since we only need the **last** word, why start from the beginning? If we start from the end of the string, the first word we hit is the one we want.

#### The Two Challenges:

1. **Trailing Spaces:** The string might end with spaces (e.g., `"moon  "`). We need to skip these first.
2. **Counting:** Once we hit a letter, we start counting until we hit another space or the beginning of the string.

---

### 🛠️ The Plan

1. Start a pointer `i` at the very last index of the string (`s.length() - 1`).
2. **Skip the noise:** Move `i` backward as long as `s.charAt(i)` is a space.
3. **Count the word:** Once you find a non-space character, start a counter. Move `i` backward and increment the counter until you hit a space or `i < 0`.
4. **Return** the count.

---

### 💻 Java Implementation

Here is the `.md` file for your study notes.

```markdown
# Study Note: Length of Last Word

## 📌 Problem Description
Given a string `s`, return the length of the last word. A word is defined as a maximal substring consisting of non-space characters only.

**Example:**
Input: `s = "   fly me   to   the moon  "` 
Output: `4` (The last word is "moon")

---

## 🛠️ The Strategy: Backward Iteration
Instead of splitting the whole string into an array, we traverse from right to left to find the first word we encounter.



### Steps:
1.  **Initialize**: Set a pointer `i` to the end of the string and a `length` counter to 0.
2.  **Skip Trailing Spaces**: Use a `while` loop to move `i` backward as long as the character at `i` is a space `' '`.
3.  **Count Letters**: Use another `while` loop to move `i` backward and increment `length` as long as the character is **not** a space and `i` is within bounds.
4.  **Finish**: The moment you hit a space after finding letters, the last word is complete.

---

## 💻 Java Implementation

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        int length = 0;

        // Step 1: Skip trailing spaces from the end
        while (i >= 0 && s.charAt(i) == ' ') {
            i--;
        }

        // Step 2: Count characters of the last word
        while (i >= 0 && s.charAt(i) != ' ') {
            length++;
            i--;
        }

        return length;
    }
}

```

---

## 🧠 Complexity Analysis

### Time Complexity: 

In the worst case (a string with one very long word), we visit every character once. However, on average, this is much faster than `split()` because we stop as soon as the last word is counted.

### Space Complexity: 

We only use two integer variables (`i` and `length`), regardless of how large the input string is.

---

## 🔑 Why this is better than `split()`?

* **Memory**: `split(" ")` creates an array of strings, which can be very memory-intensive for long sentences.
* **Speed**: This approach doesn't need to process the beginning of the sentence if it doesn't have to.

```

Would you like to try a problem that involves **counting frequencies** of characters next, or perhaps one that deals with **palindromes**?

```