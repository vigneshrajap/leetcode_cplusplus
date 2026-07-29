# Fast and Slow Pointers Template

## Overview

Fast and slow pointers are a same-direction two-pointer pattern.
Both pointers move forward, but at different moments or speeds.

Typical idea:

1. `fast` scans every position.
2. `slow` moves only when a condition is met.
3. `slow` often marks the boundary of a valid/processed region.

## Core Array Template (As Requested)

```cpp
#include <vector>

void two_pointers_same(std::vector<int>& arr) {
    int slow = 0, fast = 0;
    while (fast < static_cast<int>(arr.size())) {
        // Process current elements
        int current = process(arr[slow], arr[fast]);

        // Update pointers based on condition
        if (condition(arr[slow], arr[fast])) {
            slow++;
        }

        // Fast pointer always moves forward
        fast++;
    }
}
```

## Invariant Mindset

A common invariant is:

- `arr[0..slow-1]` is the processed/valid zone.
- `fast` is the current candidate being examined.

When condition is true, advance `slow` to expand the valid zone.

## Common Use Cases

- Remove duplicates from sorted array (in-place)
- Move zeros to end while preserving relative order
- Partition values by condition (keep/skip)
- Subsequence check (two strings, both move forward)
- Linked-list cycle detection (fast moves 2 steps, slow moves 1)
- Find middle of linked list

## Practical Array Variant: Remove Duplicates (Sorted)

```cpp
#include <vector>

int removeDuplicatesSorted(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int slow = 1;
    for (int fast = 1; fast < static_cast<int>(nums.size()); ++fast) {
        if (nums[fast] != nums[slow - 1]) {
            nums[slow] = nums[fast];
            ++slow;
        }
    }
    return slow;
}
```

## Linked List Fast/Slow Variant: Cycle Detection

```cpp
struct ListNode {
    int val;
    ListNode* next;
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

## Complexity

For input size n:

- Time: O(n), `fast` advances at most n times and `slow` advances at most n times.
- Space: O(1), only a constant number of pointers/variables.

For linked-list cycle detection specifically:

- Time: O(n)
- Space: O(1)

## Common Mistakes

- Not defining a clear invariant for what `slow` represents
- Accessing `arr[slow]` when array is empty
- Forgetting to cast `arr.size()` to `int` in signed comparisons
- Moving `slow` too early (before writing/committing result)
- In linked list problems, not checking `fast` and `fast->next` before jumping two steps

## Quick Mental Checklist

- What does `slow` represent at every step?
- Does `fast` always move exactly once per loop?
- When condition is true, should I move `slow`, write value, or both?
- Are boundary checks safe for empty input?
