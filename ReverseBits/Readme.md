# Reverse Bits

Given a 32-bit unsigned integer, reverse its bits and return the result as another 32-bit unsigned integer.

## Solution idea

The approach in [sample.cpp](sample.cpp) works bit by bit.

Instead of trying to reverse the whole number at once, the code processes the value one bit at a time:

1. Take the last bit of the current number.
2. Append that bit to the result.
3. Move the original number one step to the right.
4. Repeat this process 32 times.

This is possible because reversing bits means we are building the answer from the least significant bit (LSB) of the original number to the most significant bit (MSB) of the reversed number.

## How the code works

The implementation uses a loop that runs 32 times:

```cpp
for (int i = 0; i < 32; i++) {
    int bit = n & 1;
    result = (result << 1) | bit;
    n >>= 1;
}
```

### Step-by-step

- `n & 1` extracts the last bit of `n`.
  - If `n` ends in `0`, the result is `0`.
  - If `n` ends in `1`, the result is `1`.
- `result << 1` shifts the current answer left by one position, making space for the next bit.
- `| bit` adds the extracted bit to the end of the answer.
- `n >>= 1` removes the last bit from `n`, so the next iteration processes the next bit.

At the end, `result` contains the reversed bit pattern.

## Why this works

Suppose we want to reverse a binary number. The first bit of the reversed result should be the last bit of the original number.

That is why the algorithm starts from the right side of the original number and builds the answer from left to right.

Example:

If the original number is:

```text
00000010100101000001111010011100
```

The algorithm takes the last bit first, then the next one, and keeps appending them to the result. After 32 iterations, the bits are arranged in reverse order.

## Bitwise operations in detail

A fuller reference for this section has been moved to [Templates/BitwiseOperations.md](../Templates/BitwiseOperations.md).

## Complexity

- Time: $O(32)$, which is effectively $O(1)$
- Space: $O(1)$

The loop always runs exactly 32 times, so the runtime does not depend on the size of the input beyond that fixed bound.
