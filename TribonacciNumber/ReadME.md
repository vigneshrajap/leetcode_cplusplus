# Tribonacci Number

Return the `n`th Tribonacci number, where each term is the sum of the three preceding terms.

## Approach

Use iteration with three state variables to build the sequence.

### Idea

1. Return `0` for `n == 0`.
2. Return `1` for `n == 1` or `n == 2`.
3. Use three variables to store the previous terms: `n0`, `n1`, `n2`.
4. Iteratively compute the next term as `n0 + n1 + n2`.
5. Shift the window and continue until reaching `n`.

See [sample.cpp](sample.cpp).