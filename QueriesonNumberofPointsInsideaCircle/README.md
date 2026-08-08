# Queries on Number of Points Inside a Circle

Given a list of points and a list of circle queries, count how many points lie inside or on the boundary of each circle.

## Current Approach

The implementation checks every point for each query by computing the squared distance to the circle center and comparing it with the squared radius.

- For each query:
  - For each point:
    - Compute `dx = x_point - x_center`
    - Compute `dy = y_point - y_center`
    - If `dx*dx + dy*dy <= radius*radius`, increment the count for that query.

This direct approach is simple and easy to verify.

## Complexity

- Time Complexity: O(Q * P)
  - `Q` is the number of queries
  - `P` is the number of points
- Space Complexity: O(Q)
  - Output vector stores one answer per query
  - Auxiliary space is O(1)

## Alternative Approach (`sample1.cpp`)

The alternate implementation sorts points by their `x`-coordinate and uses binary search to skip points that cannot be inside the current circle.

- Sort `points` by `x` once.
- For each query:
  - Find the first point with `x >= cx - r` using `lower_bound`.
  - Scan forward while `x <= cx + r`.
  - For each candidate point, use a squared-distance check to determine if it lies inside the circle.

This reduces the number of points checked per query when the query circle covers only a small `x`-range.

### Complexity of the sorted approach

- Preprocessing Time: O(P log P) to sort the points
- Query Time: O(Q * (log P + K))
  - `K` is the number of points whose `x`-coordinate lies in the candidate range for a query
- Space Complexity: O(Q)
  - Output vector stores one answer per query
  - Auxiliary space is O(1)

## Notes

The alternative approach is better when points are spread out and queries cover narrow horizontal ranges. The direct brute-force method remains simpler and may be acceptable for smaller input sizes.
