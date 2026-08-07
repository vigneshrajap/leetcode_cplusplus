# Contains Duplicate

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

## Approach

The solution uses an `unordered_set` to track values that have already been seen while iterating through the array.

- For each number in `nums`:
  - If it is already present in the set, return `true`.
  - Otherwise, insert it into the set.
- If the loop finishes without finding a duplicate, return `false`.

## Better Solution

This is already an efficient approach for this problem. It uses an early exit, so it can stop as soon as a duplicate is found instead of scanning the rest of the array.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
```

## Lower-Memory Approach

If the input is sorted, you can solve it with less extra space by comparing adjacent elements. This avoids using a hash set and only uses a constant amount of extra memory.

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
```

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)
