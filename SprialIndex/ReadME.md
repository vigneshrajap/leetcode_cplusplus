# Spiral Matrix

Return the elements of a matrix in spiral order.

## Approach

Use boundary pointers and traverse the matrix in layers.

### Idea

1. Traverse the top row from left to right.
2. Traverse the right column from top to bottom.
3. Traverse the bottom row from right to left if still valid.
4. Traverse the left column from bottom to top if still valid.
5. Move the boundaries inward and repeat.

This yields the elements in clockwise spiral order.

See [sample.cpp](sample.cpp).