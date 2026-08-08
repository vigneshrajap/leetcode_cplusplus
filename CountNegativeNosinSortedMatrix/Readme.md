# Count Negative Numbers in a Sorted Matrix

Given a matrix `grid` where each row is sorted in non-increasing order, return the number of negative numbers in the matrix.

## Approach (`sample.cpp`) — Row scan with count_if

- For each row, use `std::count_if` to count negative values.
- Sum these counts across all rows.

### Complexity (`sample.cpp`)

- Time: O(m * n)
  - Each row is scanned fully.
- Space: O(1)
  - Only constant extra space is used.

## Approach (`sample1.cpp`) — Staircase search

- Start from the bottom-left corner of the matrix.
- If the current value is negative, then all values to the right in that row are negative, so add `n - col` to the count and move up one row.
- If the current value is non-negative, move right one column.
- Continue until you exit the matrix bounds.

This approach exploits the sorted row and column structure to skip many entries.

### Complexity (`sample1.cpp`)

- Time: O(m + n)
  - Each step moves either up or right, visiting at most `m + n` positions.
- Space: O(1)
  - Only constant extra variables are used.

## Notes

- Use `sample1.cpp` when the matrix is large and you want a faster solution than scanning every element.
- `sample.cpp` is simpler and fine for small-to-medium matrix sizes.
