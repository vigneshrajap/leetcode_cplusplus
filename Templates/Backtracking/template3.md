# Backtracking Template with Additional Constraints

## Overview

Some problems require us to maintain **additional state** beyond just the current path and index. For example, in *Palindrome Partitioning*, we check if each part is a palindrome before branching. When constraints require validation using external state, we pass those states as DFS parameters.

## General Template

```text
void dfs(int startIndex, std::vector<T> path, std::vector<std::vector<T>>& res, 
         [...additional states]) {
    if (isLeaf(path)) {
        // add a copy of the path to the result
        res.emplace_back(std::vector<T>(path));
        return;
    }
    
    for (auto edge : getEdges(startIndex, [...additional states])) {
        path.emplace_back(choice);
        
        if (...additional states) 
            update(...additional states);
        
        dfs(startIndex + edge.length(), path, res, [...additional states]);
        
        path.pop();
        // revert(...additional states) if necessary, e.g. permutations
    }
}
```

## Key Differences

- **Additional parameters**: Pass one or more state variables as DFS function parameters
- **State updates**: Update additional states when modifying `startIndex`
- **State reversion**: Revert changes to additional states when backtracking (when needed)

