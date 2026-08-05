#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        std::unordered_map<int, int> freq_map;
        std::unordered_map<int, int> ends_at; // ends_at[x] = count of sequences ending at x

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq_map[num]++;
        }

        // Step 2: Process each number greedily
        for (int num : nums) {
            // If the number was already consumed in a previous 3-element sequence, skip it
            if (freq_map[num] == 0) {
                continue;
            }

            // Option 1: Append to an existing sequence ending at num - 1
            if (ends_at[num - 1] > 0) {
                ends_at[num - 1]--;
                ends_at[num]++;
                freq_map[num]--;
            }
            // Option 2: Start a brand-new sequence of length 3 (num, num+1, num+2)
            else if (freq_map[num + 1] > 0 && freq_map[num + 2] > 0) {
                freq_map[num]--;
                freq_map[num + 1]--;
                freq_map[num + 2]--;
                ends_at[num + 2]++;
            }
            // Option 3: Neither is possible
            else {
                return false;
            }
        }

        return true;
    }
};