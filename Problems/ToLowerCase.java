class Solution {
    public String toLowerCase(String s) {
        char[] chars = s.toCharArray();
        
        for (int i = 0; i < chars.length; i++) {
            // Check if the character is within the Uppercase range
            if (chars[i] >= 'A' && chars[i] <= 'Z') {
                // Shift the character by 32 to make it lowercase
                chars[i] = (char) (chars[i] + 32);
            }
        }
        
        return new String(chars);
    }
}