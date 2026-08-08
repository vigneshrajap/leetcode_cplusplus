# Longest Substring Without Repeating Characters

Given a string `s`, find the length of the longest substring without repeating characters.

## Approach (sliding window + last-seen index)

Both implementations use a sliding-window technique that maintains a window `[left, right]` containing unique characters and expands `right` while updating `left` when duplicates are found.

### `sample.cpp` — Unordered map (generic)

- Uses `unordered_map<char,int>` to store the last index where each character appeared.
- When a duplicate character at `right` is found, move `left` to `max(last_index + 1, left)` to ensure the window contains unique characters.
- Update the last-seen index and track the maximum window length.

### `sample2.cpp` — Fixed-size array (optimized)

- Uses a fixed-size `vector<int> mpp(256, -1)` to store last-seen indices for all possible ASCII characters.
- The logic is identical to `sample.cpp`, but using an array reduces overhead and is faster for the ASCII character set.

## Complexity

- Time Complexity (both): O(n), where `n` is `s.size()`.
- Space Complexity:
  - `sample.cpp`: O(k), where `k` is the number of distinct characters stored in the unordered map (worst-case O(min(n, alphabet))).
  - `sample2.cpp`: O(1) auxiliary space (fixed 256-size array) — effectively constant.

## Notes

- Use `sample2.cpp` when the character set is known to be bounded (e.g., ASCII) for a speed and memory advantage.
- `sample.cpp` is more flexible for arbitrary Unicode character handling (if adapted appropriately).
