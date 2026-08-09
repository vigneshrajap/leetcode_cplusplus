# H-Index II

Given a sorted list of citation counts, compute the h-index.

## Approach

Use binary search to find the smallest index where `citations[i] >= n - i`.

### Idea

- `n - i` is the number of papers with at least `citations[i]` citations.
- If `citations[mid] >= n - mid`, move left to try a smaller index.
- Otherwise, move right.
- The result is `n - left` after the search finishes.

This takes advantage of the sorted citations list for O(log n) time.

See [sample.cpp](sample.cpp).