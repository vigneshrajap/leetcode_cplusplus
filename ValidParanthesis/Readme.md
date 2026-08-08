# Valid Parenthesis

Given a string `s` containing only the characters `'('`, `')'`, `'{'`, `'}'`, `'['`, and `']'`, determine if the input string is valid.

A string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.

## Approach

The solution uses a stack to track open brackets and a map to match closing brackets to their corresponding opening brackets.

- Iterate through each character in the string.
- If the character is a closing bracket, check whether the stack is non-empty and whether the top of the stack matches the expected opening bracket.
  - If not, return `false`.
  - Otherwise, pop the stack.
- If the character is an opening bracket, push it onto the stack.
- After processing all characters, the string is valid only if the stack is empty.

## Complexity

- Time Complexity: O(n)
- Space Complexity: O(n)
