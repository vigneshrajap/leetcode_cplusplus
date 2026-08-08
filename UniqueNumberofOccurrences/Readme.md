# Unique Number of Occurrences

Given an integer array `arr`, return `true` if the number of occurrences of each value in the array is unique, otherwise return `false`.

## Approach (`sample1.cpp`) — Count + set

- Use an `unordered_map<int,int>` to count the frequency of each value in `arr`.
- Use an `unordered_set<int>` to record frequencies seen so far.
- If a frequency is already in the set, return `false`.
- If we finish without collisions, return `true`.

### Complexity (`sample1.cpp`)

- Time Complexity: O(n)
  - Building the frequency map is O(n).
  - Checking uniqueness over map entries is O(k) where `k` ≤ n.
- Space Complexity: O(k)
  - Both the frequency map and the set use O(k) space where `k` is the number of distinct values.

## Alternative (`sample2.cpp`) — Two-map check (freq-of-freq)

- First build an `unordered_map<int,int>` counting occurrences of each element.
- Then build a second map (or `unordered_map<int,int> freqCount`) counting how many elements have a given frequency.
- As you increment `freqCount[p.second]`, if any frequency count becomes greater than 1, return `false` early.
- Otherwise return `true`.

### Complexity (`sample2.cpp`)

- Time Complexity: O(n)
- Space Complexity: O(k)

## Notes

- Both approaches are linear time and use additional space proportional to the number of distinct elements.
- `sample2.cpp` may be marginally faster in practice due to fewer hash-set operations and early exit on duplicate frequencies.
