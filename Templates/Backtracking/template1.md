# Backtracking Template

Backtracking explores a state-space tree by choosing one option at a time, exploring deeper, and undoing the choice afterward.

Before coding, ask:

- How do we know we have reached a solution?
- How do we generate the next possible choices?

Then use this general template:

```text
function dfs(start_index, path):
  if is_leaf(start_index):
    report(path)
    return
  for edge in get_edges(start_index):
    path.add(edge)
    dfs(start_index + 1, path)
    path.pop()
```

start_index is used to keep track of the current level of the state-space tree.

edge is the choice we make; the letters a, b in the above state-space trees.

The main logic we have to fill out is:

is_leaf
get_edges


Time and space complexity
We visit each node of the state-space tree exactly once, so the time complexity of a backtracking algorithm is proportional to the number of nodes in the state-space tree. The number of children of each node ^ height of the tree gives the number of leaf nodes, which is the dominant term, so the time complexity is O(b^h) for branching factor b and height h.

The space complexity of a backtracking algorithm is typically the height of the tree because that's where the DFS recursive call stack is of maximum height and uses the most memory.


Normally for Combinatorial problems
Time complexity
For each node there are a maximum of 2 children. The height of the tree is n. There are 2^n leaf nodes (solutions), and the total number of nodes is O(2^n), (see the "perfect binary tree" section of Everything about trees for a quick review). It takes O(n) to join the n characters at each leaf node. So the overall time complexity is O(2^n*n).

Space complexity
We store 2^n strings in total, each with a length of n so this gives us O(2^n*n) space. In addition, our recursion depth is O(n). Adding the two together, we still get a space complexity of O(2^n*n)..