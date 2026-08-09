# Maximum 69 Number

Given a number consisting only of digits `6` and `9`, maximize the number by changing at most one digit.

## Approach

Convert the number to a string, then change the first `6` to `9`.

### Idea

1. Convert the integer to its string representation.
2. Scan from left to right.
3. Replace the first `6` with `9`.
4. Convert the modified string back to an integer.

Changing the first `6` yields the maximum possible value.

See [sample.cpp](sample.cpp).