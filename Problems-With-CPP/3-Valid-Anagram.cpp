class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are different, they cannot be anagrams
        if (s.length() != t.length()){
            return false;
        }

        // Step 2: Create a frequency map (unordered_map) to count characters in string s
        unordered_map<char, int> counts;

        // Count frequency of each character in string s
        for(char c : s){
            counts[c]++;  // Increment count for this character
        }

        // Alternative traditional for loop (commented for reference):
        // for (int i = 0; i < s.length(); i++) {
        //     char current_char = s[i];
        //     counts[current_char]++;
        // }

        // Step 3: Check string t against the frequency map
        // We decrement counts as we find matching characters
        for(char c : t){
            // If character not present or count already exhausted, it's not an anagram
            if (counts[c] == 0) {
                return false;
            }
            counts[c]--;  // Use up one occurrence of this character
        }

        // Alternative traditional loop (commented):
        // for (int i = 0; i < t.length(); i++) {
        //     char current_char = t[i];
        //     
        //     if (counts[current_char] == 0) {
        //         return false; 
        //     }
        //     counts[current_char]--;
        // }

        // Step 4: If we reached here, all characters matched perfectly
        return true;
    }
};