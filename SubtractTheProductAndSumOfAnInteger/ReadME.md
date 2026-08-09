# Subtract the Product and Sum of Digits of an Integer

Given an integer `n`, return the difference between the product of its digits and the sum of its digits.

## Approach

Extract each digit, accumulate the product and sum, then return `product - sum`.

### Idea

1. If `n == 0`, return `0`.
2. While `n > 0`, extract the last digit using `n % 10`.
3. Multiply that digit into `product` and add it to `sum`.
4. Divide `n` by `10` to move to the next digit.
5. Compute and return `product - sum`.

See [sample.cpp](sample.cpp).