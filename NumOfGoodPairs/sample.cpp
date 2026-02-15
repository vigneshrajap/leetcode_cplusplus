class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq_map[101] = {0};
        int good_pairs = 0;

        // Step 1: Count frequencies
        for(int val : nums) {
            freq_map[val]++;
        }

        // Step 2: Calculate pairs for each unique number
        // We iterate through the possible values (0-100), not the input array size
        for(int i = 0; i <= 100; i++) {
            if (freq_map[i] > 1) {
                int n = freq_map[i];
                // Formula for nC2 (Choosing 2 from n)
                good_pairs += (n * (n - 1)) / 2;
            }
        }

        return good_pairs;
    }
};