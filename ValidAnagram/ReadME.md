# Valid Anagram

Check whether one string is an anagram of another.

## Approach

Use a frequency counter for lowercase letters.

### Idea

1. If `s` and `t` have different lengths, return `false`.
2. Count each character in `s`.
3. Decrement the counts for each character in `t`.
4. If any count drops below zero, the strings are not anagrams.
5. Otherwise, return `true`.

See [sample.cpp](sample.cpp).