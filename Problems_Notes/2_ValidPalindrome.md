The code uses a **Two-Pointer Technique** ✌️ to verify if a string is a palindrome while ignoring non-alphanumeric characters and case differences. This is an efficient approach because it processes the string in a single pass without creating a new, filtered version of the string in memory.

### Theoretical Logic 🧠

1. **Initialization**: We place two markers (pointers): `left` at the start (index 0) and `right` at the end (`s.length() - 1`).
2. **Filtering Non-Alphanumeric Characters**: A palindrome check only cares about letters and numbers.
* If `s.charAt(left)` is not a letter or digit, we simply skip it by incrementing `left`.
* If `s.charAt(right)` is not a letter or digit, we skip it by decrementing `right`.


3. **Symmetry Comparison**: Once both pointers land on valid characters, we compare them.
* We use `Character.toLowerCase()` to ensure the check is **case-insensitive** (e.g., 'A' matches 'a').
* If they do **not** match, the string cannot be a palindrome, so we return `false` immediately.
* If they **do** match, we move both pointers inward (`left++` and `right--`) to check the next pair.


4. **Termination**: The loop continues as long as `left < right`. If the pointers meet or cross without any mismatches being found, the function returns `true`.

### Complexity Analysis 📊

* **Time Complexity**: , where  is the length of the string. Each character is visited at most once by either the left or right pointer.
* **Space Complexity**: . No additional data structures (like a builder or a new string) are used; we only store a few integer variables.

### The Java Code 💻

```java
class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Move left pointer forward if it's not alphanumeric
            if (!Character.isLetterOrDigit(s.charAt(left))) {
                left++;
            }
            // Move right pointer backward if it is not alphanumeric
            else if (!Character.isLetterOrDigit(s.charAt(right))) {
                right--;
            }
            // Both are alphanumeric, so compare them
            else {
                // Perform case-insensitive comparison
                if (Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))) {
                    return false;
                }
                // Move pointers toward the center after a successful match
                left++;
                right--;
            }
        }
        // If pointers cross without returning false, it is a palindrome
        return true;
    }
}

```