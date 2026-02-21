class Solution {
public:
    int numSplits(string s) {
        // Since we only have lowercase English letters, 
        // arrays of size 26 are much faster than unordered_maps.
        int left_map[26] = {0};
        int right_map[26] = {0};
        
        int left_distinct = 0;
        int right_distinct = 0;
        int good_splits = 0;

        // 1. Initial Pass: Put everything in the right side
        for (char c : s) {
            if (right_map[c - 'a'] == 0) {
                right_distinct++;
            }
            right_map[c - 'a']++;
        }

        // 2. Second Pass: Move chars from right to left one by one
        // Note: i < s.size() - 1 because both parts must be non-empty.
        for (int i = 0; i < s.size() - 1; i++) {
            char current = s[i];

            // Add to left
            if (left_map[current - 'a'] == 0) {
                left_distinct++;
            }
            left_map[current - 'a']++;

            // Remove from right
            right_map[current - 'a']--;
            if (right_map[current - 'a'] == 0) {
                right_distinct--;
            }

            // 3. Compare
            if (left_distinct == right_distinct) {
                good_splits++;
            }
        }

        return good_splits;
    }
};