# Bitwise operations reference

Bitwise operations work directly on the binary representation of numbers.

## 1. AND `&`

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

## 2. OR `|`

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

## 3. XOR `^`

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

## 4. NOT `~`

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

## 5. Left shift `<<`

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

## 6. Right shift `>>`

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
