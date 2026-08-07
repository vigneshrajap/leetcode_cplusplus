# First Unique Character in a String

Given a string `s`, find the index of the first character that appears only once. If no such character exists, return `-1`.

## Approach 1: Hash Map Solution

The solution in `sample.cpp` uses an `unordered_map` to count the frequency of each character.

1. First pass: count how many times each character appears.
2. Second pass: scan the string from left to right and return the first index whose count is `1`.
3. If no such character is found, return `-1`.

### Complexity

- Time Complexity: O(n)
- Space Complexity: O(k), where `k` is the number of distinct characters

## Approach 2: Fixed-Size Array Solution

The solution in `sample1.cpp` uses a fixed-size array of length `26` to count frequencies for lowercase English letters.

1. First pass: count the frequency of each letter.
2. Second pass: find the first index whose frequency is `1`.
3. If none exists, return `-1`.

This version is more memory efficient for the lowercase alphabet case.

### Complexity

- Time Complexity: O(n)
- Space Complexity: O(1)
