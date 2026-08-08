# The K Weakest Rows in a Matrix

Given an `m x n` binary matrix `mat` where each row represents soldiers (1) followed by civilians (0), return the indices of the `k` weakest rows ordered from the weakest to the strongest. A row's strength is the number of soldiers in it.

## Approach (sample.cpp) — Priority Queue with row counts

- For each row, count the number of `1`s (`std::count` over the row).
- Push the pair `(soldier_count, row_index)` into a min-heap (priority queue with `greater` comparator).
- Pop the smallest `k` entries from the heap and collect their row indices.

### Complexity (sample.cpp)

- Time: O(m * n + m log m)
  - Counting soldiers takes O(n) per row, so O(m * n) overall.
  - Heap push for each row costs O(log m), so O(m log m) total.
- Space: O(m)
  - Priority queue stores up to `m` entries; result uses O(k) additional space.

## Approach (sample1.cpp) — Binary search per row + sort

- For each row, use binary search to find the first `0` (or count of `1`s) since rows are sorted (`1`s followed by `0`s). This takes O(log n) per row.
- Collect pairs `(soldier_count, row_index)` into a vector and then sort the vector by soldier count (and row index as a tie-breaker).
- Take the first `k` indices from the sorted vector.

### Complexity (sample1.cpp)

- Time: O(m log n + m log m)
  - Binary search per row: O(log n) each → O(m log n).
  - Sorting `m` pairs: O(m log m).
- Space: O(m)
  - Vector of `(count, index)` pairs of size `m` plus O(k) output space.

## Which to use?

- Use the binary-search + sort approach (`sample1.cpp`) when `n` (number of columns) is large and rows are long, because counting with `std::count` is O(n) while binary search costs O(log n).
- The priority-queue approach (`sample.cpp`) is simple and clear, and can be good when `m` is small or when implementation simplicity is preferred.

## Notes

- Both approaches return the correct ordering; ties are broken by row index since pairs are compared lexicographically.
- If memory is constrained, note that both methods require O(m) auxiliary space for bookkeeping.
