class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.size()==0) return 0;

        int left = 0, right = 0;
        int len = 0;
        unordered_map<char, int> mpp;

        while(right<s.size()){
            // 1. Check if we've seen this character before
            if (mpp.find(s[right]) != mpp.end()) {
                // 2. "Jump" the left pointer to the right of the old duplicate.
                // We use max() to ensure left never moves backwards.
                left = max(mpp[s[right]] + 1, left);
            }
            // Update the last seen position of the character
            mpp[s[right]] = right;

            // Calculate current window length and update max
            len = max(len, right - left + 1);
            right++;
        }

        return len;
    }

};