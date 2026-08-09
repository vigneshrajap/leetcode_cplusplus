# Fixed-Size Sliding Window Template

Use a fixed-size sliding window to evaluate every contiguous subarray of length `window_size`.

## Pattern

1. Initialize the first window with the first `window_size` elements.
2. Evaluate or store the initial window result.
3. Slide the window one step at a time by:
   - removing the element at the left boundary,
   - adding the next element on the right boundary,
   - updating the current best result.
4. Continue until the right boundary reaches the end of the array.

This pattern is useful for problems such as:
- maximum/minimum sum of subarrays of fixed length,
- maximum average subarray of size `k`,
- longest substring/window with a fixed number of characters when precomputed values are used.

## Pseudocode

```cpp
template <typename T, typename W>
W sliding_window_fixed(const std::vector<T>& input, int window_size) {
    // Initialize the first window and the best answer.
    W ans = window = std::vector<T>(input.begin(), input.begin() + window_size);

    for (int right = window_size; right < input.size(); ++right) {
        int left = right - window_size;
        // Remove the element leaving the window.
        remove input[left] from window;
        // Add the incoming element.
        append input[right] to window;
        // Update the optimal result based on the current window.
        ans = optimal(ans, window);
    }

    return ans;
}
```

## Notes

- The window size remains constant as it slides.
- `remove input[left] from window` means dropping the oldest element from the current window state.
- `append input[right] to window` adds the newest element entering the window.
- `optimal(ans, window)` represents the problem-specific update, such as choosing the maximum or minimum window value.

## Complexity

- Time: O(n) for one pass over the input.
- Space: O(window_size) for the current window state.
