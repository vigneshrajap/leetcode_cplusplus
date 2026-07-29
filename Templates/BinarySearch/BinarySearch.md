# Binary Search Boundary Template

## Overview

Boundary binary search finds the index where a monotonic condition changes.
Classic pattern: values are divided into two regions, such as:

- false ... false, true ... true

Goal: find first true (left boundary of true region), or related boundaries.

## When to Use Boundary Binary Search

- First element satisfying a condition
- Last element satisfying a condition
- First occurrence / lower bound
- Last occurrence / upper bound style queries
- Search over answer space with monotonic feasibility

## Core Idea: Monotonic Predicate

Define a predicate feasible(i) that is monotonic:

- once true, always true (for first-true search), or
- once false, always false (for last-true search with adjusted logic).

Then binary search the transition index.

## Template 1: First True (Boundary)

```cpp
#include <vector>

int firstTrueIndex(int n) {
    int left = 0;
    int right = n - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (feasible(mid)) {
            answer = mid;      // candidate boundary
            right = mid - 1;   // keep searching left half
        } else {
            left = mid + 1;
        }
    }

    return answer;
}
```

Invariant intuition:

- feasible(mid) == true means boundary is at mid or left of mid.
- feasible(mid) == false means boundary is right of mid.

## Template 2: First Element >= Target (Lower Bound)

```cpp
#include <vector>

int lowerBoundIndex(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int answer = static_cast<int>(arr.size());

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer; // n means no element >= target
}
```

## Template 3: Last True

```cpp
int lastTrueIndex(int n) {
    int left = 0;
    int right = n - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (feasible(mid)) {
            answer = mid;     // candidate
            left = mid + 1;   // keep searching right half
        } else {
            right = mid - 1;
        }
    }

    return answer;
}
```

## Why It Works

Every step discards half the search space while preserving where the boundary can still exist.
The answer variable stores the best boundary candidate seen so far.

## Complexity

For search space size n:

- Time: O(log n)
- Space: O(1)

## Common Mistakes

- Using non-monotonic feasible(i) with boundary binary search
- Midpoint overflow with (left + right) / 2 on large values
- Wrong pointer update direction after feasible(mid)
- Infinite loops from incorrect loop condition and updates
- Returning left/right directly without understanding edge cases
- Forgetting all-false or all-true scenarios

## Quick Mental Checklist

- Is predicate monotonic across index/answer space?
- Do I need first true, last true, or first >= target?
- After feasible(mid), should I move left or right boundary?
- What default answer handles no-valid-element case?
- Are my edge cases covered (empty input, all false, all true)?
