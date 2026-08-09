# Number of Good Pairs

Given an array of integers, count the number of pairs `(i, j)` such that `nums[i] == nums[j]` and `i < j`.

## Approach

Use a frequency array to count how many times each value appears, then compute combinations.

### Idea

1. Count the frequency of each number in `nums`.
2. For each value with frequency `n > 1`, add `n * (n - 1) / 2` to the result.

This computes the number of good pairs from each repeated value.

See [sample.cpp](sample.cpp).