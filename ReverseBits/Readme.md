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

Bitwise operations work directly on the binary representation of numbers.

### 1. AND `&`

`&` compares two bits and returns `1` only when both bits are `1`.

Example:

```cpp
5 & 3
```

Binary:

```text
101
011
---
001
```

Result: `1`

Use cases:

- checking whether a bit is `1`
- masking bits

In this problem:

```cpp
int bit = n & 1;
```

This extracts the last bit because `1` in binary is `000...0001`.

### 2. OR `|`

`|` compares two bits and returns `1` if at least one bit is `1`.

Example:

```cpp
5 | 3
```

Binary:

```text
101
011
---
111
```

Result: `7`

Use cases:

- setting bits to `1`
- combining bit values

In this solution:

```cpp
result = (result << 1) | bit;
```

This appends the next extracted bit to the result.

### 3. XOR `^`

`^` compares two bits and returns `1` only when the two bits are different.

Example:

```cpp
5 ^ 3
```

Binary:

```text
101
011
---
110
```

Result: `6`

Use cases:

- toggling bits
- checking whether two values differ at a bit position
- useful in problems involving parity and bit flipping

### 4. NOT `~`

`~` flips every bit: `0` becomes `1`, and `1` becomes `0`.

Example:

```cpp
~5
```

Binary `5` is:

```text
00000000000000000000000000000101
```

After applying NOT, it becomes:

```text
11111111111111111111111111111010
```

This is the two's complement representation of `-6` in a signed integer.

Use cases:

- flipping bits
- creating masks
- working with complement operations

### 5. Left shift `<<`

`<<` moves all bits to the left by a given number of positions.

Example:

```cpp
3 << 1
```

Binary `3` is `11`. Moving left by one gives:

```text
110
```

That is `6`.

This is useful because each time we want to add a new bit to the result, we need to make room for it.

### 6. Right shift `>>`

`>>` moves all bits to the right by a given number of positions.

Example:

```cpp
6 >> 1
```

Binary `6` is `110`. Moving right by one gives:

```text
011
```

That is `3`.

In this problem:

```cpp
n >>= 1;
```

removes the last bit from `n`, so we can process the next bit.

## Why `uint32_t` is used

`uint32_t` means an unsigned 32-bit integer. It is used because the problem deals with 32-bit values, and using an unsigned type avoids confusion with signed-bit behavior.

## Putting it together — common patterns

Here are some common bitwise patterns you will see often:

- Check if bit `i` is set: `(n >> i) & 1`
- Set bit `i` to `1`: `n | (1 << i)`
- Clear bit `i` (set to `0`): `n & ~(1 << i)`
- Toggle bit `i`: `n ^ (1 << i)`
- Check if `n` is even: `(n & 1) == 0`
- Multiply/divide by $2^k$: `n << k` / `n >> k`
- Check if `n` is a power of 2: `n > 0 && (n & (n - 1)) == 0`

### Why the power-of-2 trick works

A power of 2 has exactly one bit set, such as `1000`.
Subtracting `1` turns that into `0111`.
ANDing them gives `0` because there is no overlap.

For a non-power-of-2 number, there are multiple bits set, so the AND does not become zero.

## Complexity

- Time: $O(32)$, which is effectively $O(1)$
- Space: $O(1)$

The loop always runs exactly 32 times, so the runtime does not depend on the size of the input beyond that fixed bound.
