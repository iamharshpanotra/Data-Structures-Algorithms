public class ReverseString {
    class Solution {
    public void reverseString(char[] s) {
        int left = 0;
        int right = s.length -1;

        while (left < right){
            // Step 1: Swap
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            // Step 2: Moving Pointers
            left++;
            right--;
        }
    }
}
}
