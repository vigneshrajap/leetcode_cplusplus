# Maximum Number of Balls in a Box

You are given two integers `lowLimit` and `highLimit`. Each integer in this range is placed into a box based on the sum of its digits. The task is to return the maximum number of balls that end up in any single box.

## Approach

This solution uses a fixed-size array to count how many numbers fall into each digit-sum bucket.

- For each number from `lowLimit` to `highLimit`:
  - Compute the sum of its digits.
  - Increment the corresponding bucket count.
  - Track the largest bucket count seen so far.

Since the maximum possible digit sum for numbers in the given range is small, a fixed array is efficient and fast.

## Complexity

- Time Complexity: O(n * d)
- Space Complexity: O(1)

Where:
- `n` is the number of integers in the range.
- `d` is the number of digits in the current number (at most a small constant for the problem constraints).
