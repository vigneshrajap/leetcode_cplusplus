class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int n : nums) {
            // Track two largest
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }

            // Track two smallest
            if (n < min1) {
                min2 = min1;
                min1 = n;
            } else if (n < min2) {
                min2 = n;
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};