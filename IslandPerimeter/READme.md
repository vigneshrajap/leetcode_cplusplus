# Island Perimeter

## Problem

Given a `grid` of `0`s (water) and `1`s (land), return the perimeter of the island. There is exactly one island (or none), and cells are connected horizontally/vertically.

## Approach: BFS

Starting from each unvisited land cell, perform a BFS traversal across the island. For each land cell visited:

1. **Out-of-bounds sides**: Each direction that falls outside the grid contributes 1 to the perimeter (`4 - number_of_valid_neighbors`).
2. **Water neighbors**: Each valid neighbor that is water (`0`) contributes 1 to the perimeter.
3. **Unvisited land neighbors**: Enqueue them for further BFS traversal.

The total perimeter is the sum of all such contributions across all land cells.

## Complexity

- **Time**: O(m × n) — each cell is visited at most once.
- **Space**: O(m × n) — for the `visited` matrix and BFS queue.

## Key Data Structures

- `Coordinate` struct to hold `(row, col)` pairs.
- `get_neighbors()` helper returns valid in-bounds neighbors using delta arrays.
- `bfs()` accumulates the perimeter count via the `sides` reference parameter.
