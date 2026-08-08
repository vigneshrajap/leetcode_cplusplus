# Self Dividing Numbers

A self-dividing number is a number that is divisible by every digit it contains and does not contain the digit `0`.

## Approach

The solution checks each number in the range `[left, right]` and determines whether it is self-dividing.

- For each number:
  - Extract each digit using modulus and division.
  - If a digit is `0` or the number is not divisible by that digit, the number is not self-dividing.
  - If all digits divide the number, add it to the result list.

## Complexity

- Time Complexity: O((right - left + 1) * d)
- Space Complexity: O(k)

Where:
- `d` is the number of digits in the number (at most a small constant).
- `k` is the number of self-dividing numbers found in the output.
