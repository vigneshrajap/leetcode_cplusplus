# Decode XOR Array

Given an encoded array and the first value, reconstruct the original array.

## Problem idea

The encoded array is created using XOR between consecutive elements of the original array.

If the original array is:

```text
arr = [a1, a2, a3, ...]
```

then the encoded array is:

```text
encoded = [a1 ^ a2, a2 ^ a3, a3 ^ a4, ...]
```

The goal is to recover the original values using the first element and the encoded values.

## How the solution works

The code starts by placing the first value into the result array.

Then for each encoded value, it reconstructs the next original value using:

```cpp
result.push_back(result[i] ^ encoded[i]);
```

This works because XOR is reversible:

```text
a ^ b = c
```

So if we know `a` and `c`, we can recover `b` as:

```text
b = a ^ c
```

In this problem, the current value in `result[i]` is the previous original value, and `encoded[i]` is the XOR of that previous value and the next value.

So the next value is:

```text
next = previous ^ encoded[i]
```

## Why XOR is useful here

XOR is very useful when you want to reverse a transformation that combines two values.

### What XOR does

XOR stands for “exclusive OR”. It compares two bits:

- `0 ^ 0 = 0`
- `0 ^ 1 = 1`
- `1 ^ 0 = 1`
- `1 ^ 1 = 0`

So XOR returns `1` only when the two bits are different.

### Key properties of XOR

1. **Self-inverse**
   - `a ^ a = 0`
   - `a ^ 0 = a`

2. **Reversible**
   - If `c = a ^ b`, then `a = b ^ c` and `b = a ^ c`

3. **Useful for toggling**
   - XOR can turn a bit on or off depending on whether it is combined with `1` or `0`

## When XOR is useful

XOR is especially helpful in problems involving:

- recovering a value from a combined form
- finding a single number that appears once in an array
- checking if two values are different
- toggling bits
- simple encryption or encoding schemes

In this problem, it is perfect because the encoded array stores the XOR of neighboring values, and XOR can undo that relationship.

## Complexity

- Time: $O(n)$
- Space: $O(n)$

where `n` is the size of the encoded array.
