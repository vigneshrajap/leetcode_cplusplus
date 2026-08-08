# Reverse Integer

Given a 32-bit signed integer `x`, reverse its digits. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^{31}, 2^{31}-1]`, return `0`.

## Approach

The algorithm reverses the integer by extracting digits from the end and appending them to the reversed value.

- Initialize `reversedNumber` to `0`.
- While `x` is not `0`:
  - Check for overflow before multiplying `reversedNumber` by `10`.
  - Extract the last digit using `x % 10`.
  - Append the digit: `reversedNumber = reversedNumber * 10 + lastDigit`.
  - Remove the last digit from `x` using integer division `x /= 10`.
- Return the resulting number, or `0` if overflow would occur.

## Complexity

- Time Complexity: O(d)
  - `d` is the number of digits in `x`.
- Space Complexity: O(1)
