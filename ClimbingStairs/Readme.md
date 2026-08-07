# Climbing Stairs

You are given a staircase with `n` steps. You can climb either 1 or 2 steps at a time. Determine how many distinct ways you can reach the top.

## Approach

This problem can be solved in two common ways.

### 1. Dynamic Programming Solution

The main solution in `sample.cpp` uses dynamic programming with an array to build the answer step by step.

- If `n` is 0 or 1, there is only one way to reach the top.
- For each step `i` from 3 to `n`, the number of ways to reach step `i` is:
  - `dp[i - 1]` + `dp[i - 2]`
- The array stores the number of ways for each step up to `n`.

### 2. Optimized Fibonacci-style Solution

The alternative solution in `sample1.cpp` improves space usage by only keeping track of the last two values.

- `first` stores the ways to reach the previous step.
- `second` stores the ways to reach the current step.
- Each iteration updates them to move forward through the staircase.

## Complexity

- Dynamic Programming Solution: O(n) time, O(n) space
- Optimized Solution: O(n) time, O(1) space
