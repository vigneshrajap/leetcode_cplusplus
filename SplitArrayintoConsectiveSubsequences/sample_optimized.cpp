#include <vector>
#include <algorithm>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        int prev_val = 0;
        int p1 = 0, p2 = 0, p3 = 0; // Sequences ending at prev_val of lengths 1, 2, >= 3

        while (i < n) {
            int curr_val = nums[i];
            int count = 0;

            // Count occurrences of curr_val
            while (i < n && nums[i] == curr_val) {
                count++;
                i++;
            }

            // Case 1: Gap in consecutive values -> all previous sequences must end here
            if (curr_val != prev_val + 1) {
                if (p1 > 0 || p2 > 0) return false; // Incomplete sequences left dangling
                p1 = count;  // All count numbers start new length-1 sequences
                p2 = 0;
                p3 = 0;
            } 
            // Case 2: Consecutive value (curr_val == prev_val + 1)
            else {
                if (count < p1 + p2) return false; // Not enough numbers to fix incomplete sequences

                int c1 = std::max(0, count - (p1 + p2 + p3));
                int c2 = p1;
                int c3 = p2 + std::min(p3, count - p1 - p2);

                p1 = c1;
                p2 = c2;
                p3 = c3;
            }

            prev_val = curr_val;
        }

        // After processing all numbers, no incomplete sequences should remain
        return p1 == 0 && p2 == 0;
    }
};