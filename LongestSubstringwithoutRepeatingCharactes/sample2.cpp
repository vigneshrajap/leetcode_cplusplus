class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1); // Stores the last index of each character
        int left = 0, right = 0;
        int n = s.size();
        int len = 0;

        while (right < n) {
            // If the character was seen before AND is inside our current window
            if (mpp[s[right]] != -1) {
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