# Flexible Shortest Sliding Window Template

Use a variable-size sliding window to find the shortest subarray that satisfies a condition.

## Pattern

1. Expand the window by moving `right` forward and adding elements.
2. After each expansion, try to shrink the window from the left while the window remains valid.
3. Track the smallest valid window seen so far.
4. Stop when `right` reaches the end of the input.

This pattern is useful for problems such as:
- minimum size subarray sum,
- shortest substring containing all required characters,
- smallest window covering elements with a required frequency.

## Pseudocode

```cpp
template <typename T, typename W>
W sliding_window_flexible_shortest(const std::vector<T>& input) {
    initialize window, ans;
    int left = 0;
    for (int right = 0; right < input.size(); ++right) {
        append input[right] to window;
        while (valid(window)) {
            ans = std::min(ans, window);   // window is guaranteed to be valid here
            remove input[left] from window;
            ++left;
        }
    }
    return ans;
}
```

## Notes

- `window` grows until it becomes valid.
- `valid(window)` checks a problem-specific condition.
- When the window is valid, shrinking from the left finds the shortest valid window.
- `ans` stores the best valid window found so far.

## Complexity

- Time: O(n) in typical sliding window problems, assuming each element is added and removed at most once.
- Space: O(n) in the worst case for window state and auxiliary data.
