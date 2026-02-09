# Longest Common Prefix (Horizontal Scanning)

## 📌 Problem Description
Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string `""`.

**Example:**
Input: `["flower","flow","flight"]` -> Output: `"fl"`

---

## 🛠️ The Strategy: Horizontal Scanning
The idea is to find the common prefix between the first two strings, then use that result to find the common prefix with the third string, and so on.



### Steps:
1.  **Assume** the first string is the entire prefix.
2.  **Compare** this prefix with the next string in the array.
3.  **Shorten** the prefix by one character from the right until the current string starts with it.
4.  **Repeat** for all strings in the array.
5.  **Exit Early** if the prefix becomes an empty string.

---

## 💻 Java Implementation

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Edge Case: If the array is null or empty
        if (strs == null || strs.length == 0) {
            return "";
        }

        // Start by assuming the first string is the common prefix
        String prefix = strs[0];

        // Iterate through the rest of the strings
        for (int i = 1; i < strs.length; i++) {
            
            // While the current string strs[i] does not start with the prefix
            // .indexOf(prefix) returns 0 if the string starts with the prefix
            while (strs[i].indexOf(prefix) != 0) {
                
                // Shorten the prefix by one character from the end
                prefix = prefix.substring(0, prefix.length() - 1);

                // Optimization: If prefix becomes empty, no need to check further
                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
}

```

---

## 🧠 Complexity Analysis

### Time Complexity: 

Where  is the sum of all characters in all strings.

* In the worst case (e.g., all strings are the same), we compare every character.
*  where  is the number of strings and  is the average length.

### Space Complexity: 

* We only use a constant amount of extra space (the `prefix` variable), regardless of the input size. (Note: In Java, `substring` creates a new string, but we aren't storing a growing list of them).

---

## 🔑 Key Java Methods Used

* `indexOf(String str)`: Returns the index within this string of the first occurrence of the specified substring. We look for `0` to ensure it's a **prefix**.
* `substring(int beginIndex, int endIndex)`: Extracts characters. Note that the `endIndex` is exclusive.
* `isEmpty()`: Checks if the string length is 0.
