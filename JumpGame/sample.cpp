#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (i > maxReachable) return false;
            maxReachable = std::max(maxReachable, i + nums[i]);
            if (maxReachable >= n - 1) return true;
        }
        return false;
    }
};
