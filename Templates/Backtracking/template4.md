# Backtracking 2 - Aggregation

## Overview

All the backtracking problems we have seen so far ask us to generate all the combinations of things. For example, generating all combinations or permutations of letters, generating all valid parentheses, and generating all valid palindrome partitions.

In this section, we will look at problems that ask questions such as:

- Is it possible to make up a word using other words from a dictionary?
- Find the number of ways to decode a message
- Find the minimum number of coins to make up an amount

We categorize these **"aggregation"** problems because we aggregate the return value from child recursive calls to parent and bubble them up. It's very similar to how Max Depth of a Tree and Visible Tree Node aggregate return values.

Here's the backtracking template modified to aggregate return values:

## General Template

```cpp
int dfs(int startIndex, std::vector<T>& target) {
    if (isValid(target[startIndex:])) {
        return 1;
    }
    for (auto edge : getEdges(startIndex, [...additional states])) {
        if (additional states) {
            update([...additional states]);
        }
        ans = aggregate(ans, dfs(startIndex + edge.length(), [...additional states]));
        if (additional states) {
            revert([...additional states]);
        }
    }
    return ans;
}
```

## Key Differences

- **No path tracking**: We don't use a path vector and don't push/pop elements since we don't need to actually generate the solutions. We just need the aggregated value.
- **Return value aggregation**: Use return value to aggregate results from child DFS calls.
- **Aggregation strategy**: Depending on what the problem asks for, the `initial_value` and `aggregate` function can vary:

| Problem Statement | Initial Value | Aggregate Function |
|---|---|---|
| Is it possible? Does it exist? | `boolean` | Logical OR (`\|\|`) |
| Number of ways to... | `0` | Addition (`+`) |
| Maximum/Minimum ways/value to... | `0` / `INT_MIN` | `max()` / `min()` |


## Memoization

**Memoization** is a technique for saving the results of previous function calls in a data structure (like a dictionary or array) and retrieving them when the exact same call is made again. The name comes from the concept of writing things down on a **memo** for later reference.

### When to Memoize

After drawing the state-space tree, if you observe duplicate subtrees, it's a good candidate for memoization.

### What to Memoize

Consider the duplicate subtrees and identify their shared attributes. For example, in Fibonacci, duplicate subtrees share the same `n` value. Typically:
- The memo key is the `start_index` or any additional states that appear multiple times during recursion
- This allows us to avoid redundant calculations

### Example: Fibonacci with Memoization

```cpp
int fib(int n, int memo[]) {
    // Check memo; if found, return immediately
    if (memo[n] != 0) {
        return memo[n];
    }
    
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }
    
    // Recursive case with memoization
    int res = fib(n - 1, memo) + fib(n - 2, memo);
    
    // Save result to memo before returning
    memo[n] = res;
    return res;
}
```

## Time Complexity Analysis

### Benefits of Memoization

The key benefit of memoization is that we **store previously computed results** in a memo structure for **constant-time access** on future lookups.

### Complexity Without Memoization

The time complexity of backtracking is proportional to the number of nodes in the state-space tree, which can grow exponentially for problems with overlapping subproblems.

### Complexity With Memoization

With memoization, we **avoid redundant computation** of duplicate subtrees. The actual number of nodes visited is now proportional to the **size of the memo array**, resulting in significant time savings.

**Key Insight**: By caching results, we transform exponential time complexity into polynomial time (often linear or quadratic), depending on the problem structure.