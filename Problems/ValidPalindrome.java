class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() -1;

        while(left < right){
            // First moving left pointer forward if it's not alphanumeric
            if(!Character.isLetterOrDigit(s.charAt(left))){
                left++;
            }
            // Move right pointer backward if it is not alpanumeric
            else if(!Character.isLetterOrDigit(s.charAt(right))){
                right--;
            }
            // Both are alphanumeric, so compare them
            else{
                if (Character.toLowerCase(s.charAt(left))!= Character.toLowerCase(s.charAt(right))){
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
}