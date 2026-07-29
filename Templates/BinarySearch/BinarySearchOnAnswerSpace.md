# Binary Search on Answer Space Template

## Overview

Binary search on answer space is used when we are not searching an index directly.
Instead, we search a numeric answer range and ask:

- Is this candidate answer feasible?

If feasibility is monotonic, binary search finds the optimal answer in logarithmic steps.

## When to Use

- Minimize the maximum value
- Maximize the minimum value
- Minimum capacity, speed, time, or threshold
- Maximum valid distance, score, or partition size

Common interview examples include shipping capacity, eating speed, allocation limits, and spacing problems.

## Core Pattern

1. Define search bounds low and high for possible answers.
2. Define feasible(x) as monotonic over x.
3. Choose first true or last true pattern.
4. Move boundaries based on feasible(mid).

## Monotonic Feasibility Shapes

- First true shape: false false false true true true. Good for finding the minimum x that works.

- Last true shape: true true true false false false. Good for finding the maximum x that still works.

## Template 1: Find Minimum Feasible Answer (First True)

Use when question asks for minimum x such that feasible(x) is true.

```cpp
#include <vector>

int minFeasibleAnswer(int low, int high) {
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (feasible(mid)) {
            answer = mid;      // candidate minimum
            high = mid - 1;    // try smaller
        } else {
            low = mid + 1;     // need larger
        }
    }

    return answer;
}
```

## Template 2: Find Maximum Feasible Answer (Last True)

Use when question asks for maximum x such that feasible(x) is true.

```cpp
int maxFeasibleAnswer(int low, int high) {
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (feasible(mid)) {
            answer = mid;      // candidate maximum
            low = mid + 1;     // try larger
        } else {
            high = mid - 1;    // too large, go smaller
        }
    }

    return answer;
}
```

## Example Feasibility: Minimize Maximum Subarray Sum

Given array nums and k partitions, check if max partition sum can be at most limit.

```cpp
#include <vector>

bool feasibleLimit(const std::vector<int>& nums, int k, int limit) {
    int groups = 1;
    long long running = 0;

    for (int x : nums) {
        if (x > limit) return false;

        if (running + x <= limit) {
            running += x;
        } else {
            ++groups;
            running = x;
        }
    }

    return groups <= k;
}
```

## How to Choose Bounds

Good bounds often come from problem constraints:

- Minimum bound low: smallest possible valid answer, often min element, 0, or 1.

- Maximum bound high: largest possible valid answer, often sum, max constraint, or problem limit.

Tighter bounds reduce iterations.

## Complexity

If answer range size is R and feasibility check costs F:

- Time: O(F log R)
- Space: O(1) or feasibility-dependent auxiliary space

## Common Mistakes

- Feasibility function is not monotonic
- Bounds do not include true answer
- Wrong template choice first true vs last true
- Integer overflow in midpoint or feasibility arithmetic
- Returning low or high without checking intended invariant

## Quick Mental Checklist

- Is feasible(x) monotonic over the chosen range?
- Am I minimizing an answer or maximizing an answer?
- Do bounds definitely contain the optimal answer?
- After feasible(mid), should I move left boundary or right boundary?
- Is feasibility check linear and correct on edge cases?
