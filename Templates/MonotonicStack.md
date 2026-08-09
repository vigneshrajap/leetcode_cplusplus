# Monotonic Stack Template

A monotonic stack keeps elements in increasing or decreasing order while processing a sequence.

## Pattern

- Use a stack-like container to maintain a monotonic order.
- For each new entry, remove items from the stack until the monotonic property is restored.
- After removing invalid items, push the current entry.

This is commonly used for problems such as:
- next greater element,
- nearest smaller element,
- maximum sliding window,
- histogram area calculations.

## Pseudocode

```cpp
void mono_stack(const std::vector<int>& insert_entries) {
    std::vector<int> stack;
    for (int entry : insert_entries) {
        while (!stack.empty() && stack.back() <= entry) {
            // Do something with the top item in stack here
            stack.pop_back();
        }
        stack.push_back(entry);
    }
}
```

## Notes

- The comparison direction (`<=`, `<`, `>=`, or `>`) determines whether the stack is increasing or decreasing.
- `stack.back()` represents the current candidate from the stack top.
- The inner loop removes obsolete elements before inserting the new entry.
- The comment `Do something with the top item in stack here` is where you apply problem-specific logic such as recording a next greater/smaller answer.

## Complexity

- Time: O(n) because each entry is pushed and popped at most once.
- Space: O(n) for the stack.
