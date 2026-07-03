class Solution {
    public String reverseWords(String s) {
        char[] chars = s.toCharArray();
        int start = 0;

        for (int end = 0; end < chars.length; end++) {
            if (chars[end] == ' ' || end == chars.length - 1) {
                int right = (chars[end] == ' ') ? end - 1 : end;
                reverse(chars, start, right);
                
                start = end + 1;
            }
        }
        return new String(chars);
    }

    private void reverse(char[] c, int i, int j) {
        while (i < j) {
            char temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            i++;
            j--;
        }
    }
}