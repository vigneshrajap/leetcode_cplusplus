# Convert Binary Number in a Linked List to Integer

Given the head of a singly linked list where each node stores a bit value (`0` or `1`), return the decimal value of the binary number represented by the linked list.

Example:
- Input: `1 -> 0 -> 1`
- Output: `5`

Because the linked list represents a binary number from left to right, the value is computed as:
- `101` in binary = `1*2^2 + 0*2^1 + 1*2^0 = 5`

## How the sample solution works
The sample implementation:
1. Traverses the linked list from the head.
2. Collects each bit into a string.
3. Converts that binary string into an integer using C++'s base-2 parsing.

The key line is:
```cpp
return std::stoi(str, nullptr, 2);
```
This means:
- `str` is the binary string
- `2` tells C++ to parse it as base 2
- the result is returned as a decimal integer

## Binary to integer in C++
There are several ways to convert binary to an integer:

### 1. Using `std::stoi`
```cpp
std::string binary = "101";
int value = std::stoi(binary, nullptr, 2);
```
This gives `value = 5`.

### 2. Using manual bit processing
```cpp
int value = 0;
for (char c : binary) {
    value = value * 2 + (c - '0');
}
```
This also produces `5` for `"101"`.

## Integer to binary in C++
To convert an integer to binary, you can use:

### 1. Using `std::bitset`
```cpp
#include <bitset>
#include <iostream>

int value = 5;
std::string binary = std::bitset<8>(value).to_string();
std::cout << binary; // 00000101
```

### 2. Using manual bit operations
```cpp
#include <string>
#include <algorithm>

std::string toBinary(int n) {
    std::string bits;
    while (n > 0) {
        bits.push_back((n % 2) + '0');
        n /= 2;
    }
    std::reverse(bits.begin(), bits.end());
    return bits;
}
```
Example:
```cpp
std::cout << toBinary(5); // 101
```

## Summary
- A linked list of bits can be converted into a decimal integer by building the binary string and parsing it as base 2.
- In C++, binary-to-integer conversion is commonly done with `std::stoi(..., 2)` or by shifting and accumulating bits.
- Integer-to-binary conversion can be done with `std::bitset` or by repeatedly dividing by 2.
