# Backtracking 3 - Deduplication

## Overview

The problem asks: given an array `nums` and a `target`, find all **unique triplets** where `nums[i] + nums[j] + nums[k] = target` and `i`, `j`, `k` are different indices.

**Key Constraints:**
- Equal values are allowed in a triplet as long as they come from different positions (e.g., `[1, 1, 2]` requires at least two 1s in the input)
- The word **"unique"** is critical: each distinct triplet should appear only once in the output
- Example: With `nums = [1, 1, 2, 3]` and `target = 6`, the triplet `[1, 2, 3]` should appear only once, even though we can form it using either of the two 1s

## The Problem: Duplicates

The naive approach fails because we can reduce three-sum to two-sum by fixing the first number. Here's the **broken version** without deduplication:

```python
def threeSum(nums, target):
    result = []
    for i in range(len(nums)):
        tuples = twoSum(nums, target - nums[i])
        for pair in tuples:
            result.append([nums[i]] + pair)
    return result
```

### Example: Why This Fails

With `nums = [1, 1, 2, 3]` and `target = 6`:

| i | nums[i] | twoSum Result | Output | Issue |
|---|---------|---------------|--------|-------|
| 0 | 1 | [2, 3] | [1, 2, 3] | ✓ |
| 1 | 1 | [2, 3] | [1, 2, 3] | ✗ Duplicate! |
| 2 | 2 | [1, 3] | [2, 1, 3] | ✗ Same triplet, different order |
| 3 | 3 | [1, 2] | [3, 1, 2] | ✗ Same triplet again |

## Solution: Skip Duplicate Inputs

### Strategy

1. **Sort the array** first - this groups identical values together
2. **Skip duplicate starting values** - when we encounter a value that equals the previous value, skip it because the previous iteration already handled all triplets starting with that value

### Implementation

```python
def threeSum(nums, target):
    nums.sort()  # [1, 1, 2, 3]
    result = []
    for i in range(len(nums)):
        # Skip duplicate starting value
        if i > 0 and nums[i] == nums[i-1]:
            continue
        tuples = twoSum(nums, target - nums[i])
        for pair in tuples:
            result.append([nums[i]] + pair)
    return result
```

### Example: Deduplication in Action

With sorted `nums = [1, 1, 2, 3]` and `target = 6`:

| i | nums[i] | Action | Result |
|---|---------|--------|--------|
| 0 | 1 | Process (first occurrence) | [1, 2, 3] ✓ |
| 1 | 1 | Skip (duplicate of previous) | — |
| 2 | 2 | Process | [2, 1, 3] |
| 3 | 3 | Process | [3, 1, 2] |

## Examples

### Example 1: Combination Sum

**Problem Description:**

Given an array of distinct integers `candidates` and a target integer `target`, return a list of all unique combinations of candidates where the chosen numbers sum to `target`.

**Key Notes:**
- The same number may be chosen from `candidates` an unlimited number of times
- Two combinations are unique if the frequency of at least one chosen number is different
- Combinations can be returned in any order
- The number of unique combinations is guaranteed to be less than 150

**Example:**

```
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
```

**Complexity Analysis:**

| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| Time | O(n^(target/min(candidates))) | State-space tree has n branches; depth = target/min(candidates); exponential time |
| Space | O(target/min(candidates)) | Maximum height of recursion tree = target/min(candidates) |

### Example 2: Subsets

**Problem Description:**

Given a set of distinct integers `nums`, return all possible subsets (the power set).

**Key Notes:**
- The solution set must not contain duplicate subsets
- Return all possible combinations including the empty set

**Example:**

```
Input: nums = [1, 2, 3]
Output: [
  [],
  [1],
  [2],
  [3],
  [1, 2],
  [1, 3],
  [2, 3],
  [1, 2, 3]
]
```

**Complexity Analysis:**

| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| Time | O(n × 2^n) | There are 2^n possible subsets; building each takes O(n) time |
| Space | O(n × 2^n) | Storage for all 2^n subsets, each with average length n/2 |

