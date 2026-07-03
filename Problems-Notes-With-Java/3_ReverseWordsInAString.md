# Study Note: Reverse Words in a String III

## 📌 Problem Description
Given a string `s`, reverse the order of characters in each word while preserving whitespace and the original word order.

**Example:**
Input: `"Let's take LeetCode contest"`
Output: `"s'teL ekat edoCteeL tsetnoc"`

---

## 🛠️ The Strategy: Two-Pointer In-Place Reversal
Since Java Strings are immutable, we convert the string to a `char[]` to modify it efficiently. We then identify each word's boundaries and reverse the characters between those boundaries.



### Steps:
1.  **Convert** the String to a `char[]`.
2.  **Iterate** through the array using a pointer (`j`).
3.  **Identify Boundaries**:
    * A word ends when `j` reaches a space `' '`.
    * The last word ends when `j` reaches the end of the array (`n-1`).
4.  **Reverse**: When a boundary is found, use a helper function to swap characters from the `start` of the word to the `end`.
5.  **Reset**: Update the `start` pointer to the beginning of the next word.

---

## 💻 Java Implementation

```java
class Solution {
    public String reverseWords(String s) {
        // Convert to char array for in-place modification
        char[] chars = s.toCharArray();
        int start = 0;
        
        for (int j = 0; j < chars.length; j++) {
            // Check if we hit a space or the end of the string
            if (chars[j] == ' ' || j == chars.length - 1) {
                
                // Determine the end of the current word
                // If it's a space, the word ends at j-1. If it's the end of string, it's j.
                int end = (chars[j] == ' ') ? j - 1 : j;
                
                // Reverse the identified word
                reverse(chars, start, end);
                
                // Move the start pointer to the beginning of the next word
                start = j + 1;
            }
        }
        
        return new String(chars);
    }

    // Helper method: Classical Two-Pointer Swap
    private void reverse(char[] c, int left, int right) {
        while (left < right) {
            char temp = c[left];
            c[left] = c[right];
            c[right] = temp;
            left++;
            right--;
        }
    }
}

```

---

## 🧠 Complexity Analysis

### Time Complexity: 

* We traverse the string once to find boundaries ().
* Each character is swapped at most once ().
* Total time complexity is linear relative to the length of the string.

### Space Complexity: 

* In Java, we must create a `char[]` to modify the string, which takes  space.
* The `reverse` helper uses  extra space for the `temp` variable.

---

## 🔑 Key Takeaways

* **Immutability**: Remember that `String` in Java cannot be changed. Using `char[]` or `StringBuilder` is necessary for manipulation.
* **Two-Pointer Swap**: This is the most efficient way to reverse any sequence.
* **Boundary Logic**: Always pay close attention to the last word in a sentence, as it usually doesn't end with a space!
