# Two Sum

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

## Approach

This implementation uses a hash map to store previously seen values and their indices.

- Iterate through the array.
- For each number `nums[i]`, compute the required complement `target - nums[i]`.
- If the complement is already in the map, return the stored index and the current index.
- Otherwise, store the current number and its index in the map.

This allows finding the pair in a single pass through the array.

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)
