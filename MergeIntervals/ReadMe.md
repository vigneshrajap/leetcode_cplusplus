
# Merge Intervals

Given a collection of intervals, merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

## Approach

The canonical solution follows two simple steps:

1. Sort the intervals by start time.
2. Scan the sorted list and build a `result` list of merged intervals:
   - If the current interval overlaps the last interval in `result` (current start <= last end), extend the last interval's end to `max(last_end, current_end)`.
   - Otherwise, append the current interval to `result`.

### Idea

Sorting guarantees that when we process an interval, any possible overlap can only be with the most recently kept interval. That lets us merge greedily in a single pass after sorting.

See the implementation in [MergeIntervals/sample.cpp](MergeIntervals/sample.cpp#L1-L60).

## Example

- Input: [[1,3],[2,6],[8,10],[15,18]]
- Output: [[1,6],[8,10],[15,18]]

## Why this works

After sorting by start times, intervals that overlap must be adjacent (or overlapping chains become adjacent). Merging the current interval into the last kept interval preserves coverage and never prevents future merges because the merged interval's end is the maximum of the two.

### Overlap property

Two intervals `[a.start,a.end]` and `[b.start,b.end]` do NOT overlap when `a.end < b.start` or `b.end < a.start` (one interval lies entirely to the left of the other).
Negating that gives the positive test used by the merging algorithm:

- They overlap iff `a.start <= b.end && b.start <= a.end`.

Reference image: https://algo.monster/interval_pattern_intro/overlap-condition.svg

## Complexity

- Time: $O(n \log n)$ — sort takes $O(n \log n)$, the merging pass is $O(n)$.
- Space: $O(n)$ — worst-case the output contains all intervals; `std::sort` may use $O(\log n)$ auxiliary stack space.

## C++ implementation notes

- The solution uses `std::sort` on `vector<vector<int>>` and a single pass to merge in-place into a `result` vector.
- See `[MergeIntervals/sample.cpp](MergeIntervals/sample.cpp#L1-L60)` for the exact code and small implementation details.

