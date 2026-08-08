# Isomorphic Strings

Given two strings `s` and `t`, determine whether they are isomorphic.

Two strings are isomorphic if the characters in `s` can be replaced to get `t`, with the requirement that:
- Each character in `s` maps to exactly one character in `t`.
- No two different characters in `s` map to the same character in `t`.
- The character mapping is consistent across the entire string.

## Approach

The solution uses two hash maps to enforce a one-to-one mapping in both directions.

- Iterate through each character index `i`.
- If `s[i]` has been mapped before, confirm it maps to `t[i]`.
- If `t[i]` has been mapped before, confirm it maps to `s[i]`.
- If either mapping is inconsistent, return `false`.
- Otherwise, record the mapping in both directions.
- Return `true` if all character pairs are consistent.

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(k)

Where:
- `n` is the length of the strings.
- `k` is the number of distinct characters in the strings.
