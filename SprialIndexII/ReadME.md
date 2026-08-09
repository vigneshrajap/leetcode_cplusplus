# Spiral Matrix II

Generate an `n x n` matrix filled in spiral order with integers from `1` to `n^2`.

## Approach

Use four boundaries (`top`, `bottom`, `left`, `right`) and fill the matrix layer by layer.

### Idea

1. Fill the top row from left to right.
2. Fill the right column from top to bottom.
3. Fill the bottom row from right to left, if needed.
4. Fill the left column from bottom to top, if needed.
5. Move the boundaries inward and repeat.

Continue until all values are assigned.

See [sample.cpp](sample.cpp).