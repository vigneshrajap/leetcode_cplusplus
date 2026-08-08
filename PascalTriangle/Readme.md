# Pascal's Triangle

Generate the first `numRows` of Pascal's Triangle.

## Approach (`sample.cpp`)

- Build the triangle row by row.
- Each row has `i + 1` elements for row index `i`.
- Initialize each row with `1`s.
- Fill in the inner values of the row using the previous row:
  - `row[j] = triangle[i - 1][j] + triangle[i - 1][j - 1]`
- Add each completed row to the triangle.

## Complexity

- Time Complexity: O(numRows^2)
  - Each row `i` performs `O(i)` work, so the total is `1 + 2 + ... + numRows = O(numRows^2)`.
- Space Complexity: O(numRows^2)
  - The generated triangle stores `1 + 2 + ... + numRows` values.

## Notes

- There is no `sample1.cpp` implementation in this folder, so this README documents the available `sample.cpp` solution.
