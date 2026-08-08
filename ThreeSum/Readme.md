# 3Sum

Given an array of integers `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

## Approach in `sample1.cpp`

This implementation sorts the array and then uses a hash map for each fixed first element.

- Sort `nums`.
- For each index `i`:
  - Skip duplicate values for `nums[i]`.
  - Use a hash map to store counts of the second element values from the suffix.
  - For each `j > i`, check whether the complement `-(nums[i] + nums[j])` exists in the map.
  - Add the triplet when a valid complement is found.

### Complexity for `sample1.cpp`

- Time Complexity: O(n^2)
  - Sorting takes O(n log n)
  - The nested loops over `i` and `j` yield O(n^2) work
- Space Complexity: O(n)
  - The hash map stores suffix frequencies in the worst case

## Approach in `sample2.cpp`

This implementation also sorts the array, then uses a two-pointer technique to find pairs that complement the fixed first element.

- Sort `nums`.
- For each index `i`:
  - Skip duplicate values for `nums[i]`.
  - Use two pointers `left` and `right` to search the remaining range for `nums[left] + nums[right] == -nums[i]`.
  - Move pointers inward and skip duplicates when a triplet is found.

### Complexity for `sample2.cpp`

- Time Complexity: O(n^2)
  - Sorting takes O(n log n)
  - Each `i` iterates with two pointers in linear time
- Space Complexity: O(1)
  - Only constant extra space is used beyond the output list

## Notes

- Both approaches require sorting to handle duplicates and preserve order.
- The two-pointer method in `sample2.cpp` is generally preferred for its lower auxiliary space usage.
