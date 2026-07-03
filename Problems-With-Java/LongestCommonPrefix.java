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
