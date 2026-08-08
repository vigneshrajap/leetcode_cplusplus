# Number of Good Ways to Split a String

Given a string `s`, return the number of ways to split it into two non-empty parts such that the number of distinct letters in the left part is equal to the number of distinct letters in the right part.

## Approach (`sample.cpp`)

This implementation uses two fixed-size character frequency arrays because the input is restricted to lowercase English letters.

- Initialize `left_map` and `right_map` with 26 zeros.
- Count the frequency of each character in `right_map` and track `right_distinct`.
- Iterate over the string, moving one character at a time from the right partition to the left partition:
  - Increment the left frequency and update `left_distinct` when a new character appears on the left.
  - Decrement the right frequency and update `right_distinct` when a character disappears from the right.
  - If `left_distinct == right_distinct`, increment the count of good splits.

## Complexity

- Time Complexity: O(n)
  - The string is scanned twice: once to initialize the right frequencies and once to evaluate splits.
- Space Complexity: O(1)
  - Uses constant-size arrays of length 26 and a few integer counters.

## Notes

- There is no `sample1.cpp` implementation in this folder, so this README documents the available `sample.cpp` solution.
- The fixed-size array approach is efficient and ideal for lowercase-letter inputs.
