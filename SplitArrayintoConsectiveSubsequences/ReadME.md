# Split Array into Consecutive Subsequences

## Problem
Given an integer array `nums` sorted in non-decreasing order, return `true` if it is possible to split the array into one or more subsequences such that:
- Each subsequence is of length at least 3.
- Each subsequence consists of consecutive integers.

## Approach
Use a greedy algorithm with two hash maps:
- `freq_map` counts how many times each number appears.
- `ends_at` tracks how many subsequences currently end at a given value.

For each number in `nums`:
1. Skip it if it has already been used.
2. If there is an existing subsequence ending at `num - 1`, extend that subsequence.
3. Otherwise, try to start a new subsequence with `num`, `num + 1`, and `num + 2`.
4. If neither option works, return `false`.

## C++ Sample Solution
```cpp
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isPossible(std::vector<int>& nums) {
        std::unordered_map<int, int> freq_map;
        std::unordered_map<int, int> ends_at;

        for (int num : nums) {
            freq_map[num]++;
        }

        for (int num : nums) {
            if (freq_map[num] == 0) {
                continue;
            }

            if (ends_at[num - 1] > 0) {
                ends_at[num - 1]--;
                ends_at[num]++;
                freq_map[num]--;
            } else if (freq_map[num + 1] > 0 && freq_map[num + 2] > 0) {
                freq_map[num]--;
                freq_map[num + 1]--;
                freq_map[num + 2]--;
                ends_at[num + 2]++;
            } else {
                return false;
            }
        }

        return true;
    }
};
```

## Complexity
- Time Complexity: `O(n)` where `n` is the number of elements in `nums`.
- Space Complexity: `O(n)` due to the frequency and subsequence-end tracking maps.

## Optimized C++ Sample Solution
The optimized solution processes the sorted array in one pass by grouping equal values and tracking how many sequences end at the previous value with lengths:
- `p1`: sequences of length 1 (incomplete)
- `p2`: sequences of length 2 (incomplete)
- `p3`: sequences of length 3 or more (already valid)

For each distinct value:
- If it is not consecutive to the previous value, all incomplete sequences must be closed and the current value starts new length-1 sequences.
- If it is consecutive, the current value must first extend all `p1` and `p2` sequences, then any remaining count can either continue longer sequences or start new sequences.
- At the end, the answer is valid only if no incomplete sequences remain (`p1 == 0 && p2 == 0`).

```cpp
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

            while (i < n && nums[i] == curr_val) {
                count++;
                i++;
            }

            if (curr_val != prev_val + 1) {
                if (p1 > 0 || p2 > 0) return false;
                p1 = count;
                p2 = 0;
                p3 = 0;
            } else {
                if (count < p1 + p2) return false;

                int c1 = std::max(0, count - (p1 + p2 + p3));
                int c2 = p1;
                int c3 = p2 + std::min(p3, count - p1 - p2);

                p1 = c1;
                p2 = c2;
                p3 = c3;
            }

            prev_val = curr_val;
        }

        return p1 == 0 && p2 == 0;
    }
};
```

## Optimized Complexity
- Time Complexity: `O(n)` in a single pass over `nums`.
- Space Complexity: `O(1)` additional space, using only a few counters.
