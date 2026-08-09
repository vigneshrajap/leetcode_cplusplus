# Prefix Sum Template

Prefix sum is a technique for preprocessing an array so that range sum queries can be answered quickly.

## How it works

Given an array `arr`, the prefix sum array `prefixSum` stores the cumulative sum up to each position:

- `prefixSum[i]` = `arr[0] + arr[1] + ... + arr[i]`

Once computed, the sum of any subarray from `left` to `right` (inclusive) can be obtained in O(1) time:

- If `left == 0`, the range sum is `prefixSum[right]`.
- Otherwise, the range sum is `prefixSum[right] - prefixSum[left - 1]`.

This avoids recomputing sums for every query.

## C++ template

```cpp
std::vector<int> buildPrefixSum(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> prefixSum(n);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    return prefixSum;
}

// Query sum of range [left, right] (inclusive)
int queryRange(const std::vector<int>& prefixSum, int left, int right) {
    if (left == 0) {
        return prefixSum[right];
    }
    return prefixSum[right] - prefixSum[left-1];
}
```

## Complexity

- Build prefix sum: O(n) time, O(n) space
- Query range sum: O(1) time
