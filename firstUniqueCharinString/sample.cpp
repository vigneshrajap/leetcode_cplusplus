class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> count_map;

        // 1. Fill the map with counts
        for(char c : s){
            count_map[c]++;
        }

        // 2. Loop through the STRING (not the map) to preserve order
        for(int i = 0; i < s.length(); i++) {
            // Check the count of the current character s[i]
            if (count_map[s[i]] == 1) {
                return i; // This is the first index where count is 1
            }
        }

        return -1;
    }
};