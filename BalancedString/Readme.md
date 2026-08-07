# Balanced String Split

You are given a string `s` consisting only of `'L'` and `'R'`. A balanced split is a partition of the string into the minimum number of contiguous substrings such that each substring contains an equal number of `'L'` and `'R'`.

## Approach

This solution scans the string from left to right while maintaining a running balance:

- Increase the balance for each `'R'`.
- Decrease the balance for each `'L'`.
- Whenever the balance becomes `0`, a balanced substring has been completed, so increment the answer.

This works because each time the balance returns to zero, the characters seen so far form a valid balanced split.

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(1)
