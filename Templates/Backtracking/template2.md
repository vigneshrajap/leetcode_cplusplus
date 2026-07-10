# Backtracking Template

## When to Prune a Branch

A branch should be pruned when it's clear that going into that branch would **not yield a valid final state**. This typically occurs when the problem has one or more constraints that the branch violates.

## General Template

```text
function dfs(start_index, path):
    if is_leaf(start_index):
        report(path)
        return
    
    for edge in get_edges(start_index):
        # prune if needed
        if not is_valid(edge):
            continue
        
        path.add(edge)
        # increment start_index
        dfs(start_index + len(edge), path)
        path.pop()
```

## Key Differences from Basic Backtracking

- **Pruning step**: Checks if a branch is valid using `is_valid()` before proceeding
- **Variable increment**: Increment `start_index` by variable size instead of always by 1
