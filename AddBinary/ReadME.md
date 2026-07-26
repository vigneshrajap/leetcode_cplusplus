# Add Binary

Given two binary strings `a` and `b`, return their sum as a binary string.

## Approach

The solution in [sample.cpp](sample.cpp) performs addition exactly the way we do it by hand, but in binary.

### Idea

We process the strings from right to left, just like adding numbers column by column.

At each step:

1. Take the current bit from `a` and `b`.
2. Add them together along with any carry from the previous position.
3. Compute the current output bit and the next carry.
4. Continue until both strings are fully processed.
5. Reverse the result because we built it from right to left.

### Binary rules

For each position:

- `0 + 0 + carry = 0`, carry `0`
- `0 + 1 + carry = 1`, carry `0`
- `1 + 1 + carry = 0`, carry `1`

This is the same logic used in normal addition, just with base 2.

## Example

If `a = "1010"` and `b = "1011"`:

- Start from the right:
  - `0 + 1 = 1`
  - `1 + 1 = 10` → write `0`, carry `1`
  - `0 + 0 + 1 = 1`
  - `1 + 1 = 10` → write `0`, carry `1`
- Final result: `10101`

## Why this works

The algorithm simulates binary addition one bit at a time. Since every position is handled independently and the carry is passed forward, the final string is exactly the sum of the two inputs.

## C++ Implementation Idea

The code uses:

- `i` and `j` to track positions in `a` and `b`
- `carry` to hold the value passed to the next bit
- `res` to collect the answer from right to left

After the loop finishes, the characters are reversed because they were appended in reverse order.

### How the `'0'` offset works

In the code, values like `sum % 2` are converted back into characters with:

```cpp
res += (sum % 2) + '0';
```

This works because characters in C++ are stored as integers. The character `'0'` has the ASCII value 48, so adding `0` or `1` to it gives the ASCII values for `'0'` or `'1'`:

- `0 + '0'` → `'0'`
- `1 + '0'` → `'1'`

So the expression converts the integer bit value into the correct character for the string.

The opposite idea appears when reading input bits:

```cpp
a[i] - '0'
```

Here, the character `'0'` is subtracted from a digit character like `'0'` or `'1'` to turn it into an integer value:

- `'0' - '0'` → `0`
- `'1' - '0'` → `1`

This is the same offset idea, but in reverse: it converts a character digit into its numeric form.

## Complexity

- Time: $O(n + m)$
- Space: $O(n + m)$

where `n` is the length of `a` and `m` is the length of `b`.

## About `stoi` and binary-literal solutions

Some people might try to solve this by converting the strings to integers first, such as using `stoi(a, nullptr, 2)` and `stoi(b, nullptr, 2)`.

That can work for small inputs, but it is usually not the best approach here because:

- very long binary strings may overflow standard integer types
- the extra conversion steps are unnecessary
- the problem is naturally string-based and easier to solve directly

A binary-literal style such as `0b1010` is also not a great fit because the input values are dynamic strings, not fixed constants known in advance.

## Why the manual solution is better

The manual bit-by-bit solution is a better choice because it:

- handles large inputs safely
- avoids overflow issues
- works directly with the given input format
- runs in linear time
- is simple and easy to reason about
