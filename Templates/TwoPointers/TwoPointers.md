# Two Pointers Template

## Overview

Two pointers is a technique for arrays, strings, and linked lists where we move two positions with a clear rule.
It often turns a naive O(n^2) pair-check approach into O(n).

Core ingredients:

1. Two pointers (`left/right`, `slow/fast`, or window bounds).
2. A condition that checks values at those pointers.
3. A rule for which pointer to move next.
4. Optional answer update while moving.

## When to Use Two Pointers

- Sorted array pair problems (sum/target comparisons)
- Palindrome checks and symmetric comparisons
- In-place compaction or deduplication
- Subsequence checks
- Linked-list cycle/middle detection (fast and slow)

## Opposite Direction Template (Classic on Sorted Array)

```cpp
#include <vector>

void twoPointersOpposite(std::vector<int>& arr) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left < right) {
        // Process current pair arr[left], arr[right].
        int current = arr[left] + arr[right];

        // Move one pointer based on decision rule.
        if (current < 0) {
            ++left;
        } else {
            --right;
        }
    }
}
```

Typical decision rule for sorted arrays:

- If sum is too small, move `left` rightward.
- If sum is too large, move `right` leftward.

## Same Direction Template (Read/Write Pointers)

Useful for in-place filtering or deduplication.

```cpp
#include <vector>

int removeDuplicatesSorted(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int write = 1;
    for (int read = 1; read < static_cast<int>(nums.size()); ++read) {
        if (nums[read] != nums[write - 1]) {
            nums[write] = nums[read];
            ++write;
        }
    }
    return write;  // new length
}
```

## Fast and Slow Template (Linked List)

Useful for cycle detection or finding the middle node.

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

## Two Pointers vs Sliding Window

Sliding window is a two-pointer family where pointers represent a window `[left, right]` over contiguous elements.

- Fixed-size window: move both ends together.
- Variable-size window: expand `right`, shrink `left` when constraint breaks.

If a problem asks about contiguous subarray/substring optimization, think sliding window first.

## Decision Table

| Problem Pattern | Preferred Strategy | Why |
|---|---|---|
| Sorted array pair sum/comparison | Opposite direction (`left`, `right`) | Use ordering to eliminate one side each step |
| Palindrome / symmetric checks | Opposite direction | Compare mirrored positions from both ends |
| In-place dedup / compaction | Same direction (`read`, `write`) | Keep valid prefix and overwrite unwanted values |
| Subsequence check | Same direction (two forward pointers) | Preserve order while scanning once |
| Linked list cycle / middle | Fast and slow pointers | Relative speed reveals cycle or midpoint |
| Contiguous subarray/substring constraints | Sliding window (two pointers on a window) | Expand/shrink interval while maintaining invariant |
| Need shortest-by-edges in graph/tree | Not two pointers (use BFS) | Pointer movement does not model graph layers |

Quick rule:

- If data is sorted and pair relation matters, start with opposite direction.
- If editing in place or preserving order, start with same direction.
- If contiguous ranges drive the condition, start with sliding window.

## Complexity

For input size n (typical forms):

- Time: O(n), each pointer usually moves at most n times.
- Space: O(1), in-place pointer movement.

## Common Mistakes

- Applying opposite-direction logic to unsorted arrays
- Moving both pointers when only one should move by rule
- Infinite loop due to missing pointer updates
- Off-by-one bounds (`left <= right` vs `left < right`)
- Mixing two-pointers with sliding-window invariants

## Quick Mental Checklist

- Which shape fits: opposite, same direction, or fast/slow?
- What invariant must remain true after each move?
- What exact condition decides which pointer moves?
- Are loop boundaries and pointer updates guaranteed to terminate?
