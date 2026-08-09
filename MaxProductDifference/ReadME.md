# Maximum Product Difference

Given an integer array, return the maximum product difference between two pairs.

## Approach

Track the two largest and two smallest values in a single pass.

### Idea

1. Maintain `max1`, `max2` for the two largest numbers.
2. Maintain `min1`, `min2` for the two smallest numbers.
3. For each number, update these values.
4. Return `(max1 * max2) - (min1 * min2)`.

This avoids sorting and runs in O(n) time.

See [sample.cpp](sample.cpp).