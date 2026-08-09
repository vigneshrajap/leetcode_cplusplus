# Flexible Longest Sliding Window Template

Use a variable-size sliding window to find the longest subarray or substring that satisfies a validity condition.

## Pattern

1. Expand the window by moving `right` forward and adding elements.
2. If the window becomes invalid, shrink it from the left until it is valid again.
3. After restoring validity, update the best answer.
4. Continue until `right` reaches the end of the input.

This pattern is useful for problems such as:
- longest substring without repeating characters,
- longest subarray with at most `k` distinct elements,
- longest valid window under some constraint.

## Pseudocode

```cpp
template <typename T, typename W>
W sliding_window_flexible_longest(const std::vector<T>& input) {
    initialize window, ans;
    int left = 0;
    for (int right = 0; right < input.size(); ++right) {
        append input[right] to window;
        while (invalid(window)) {
            remove input[left] from window;
            ++left;
        }
        ans = std::max(ans, window);       // window is guaranteed to be valid here
    }
    return ans;
}
```

## Notes

- `window` grows with `right` until it becomes invalid.
- `invalid(window)` is problem-specific and controls shrinking.
- Once the window is valid again, the current window is a candidate for the longest valid window.
- `ans` tracks the best valid window seen so far.

## Complexity

- Time: O(n) for typical sliding window problems, assuming each element is added and removed at most once.
- Space: O(n) in the worst case for auxiliary window state and tracking data.
