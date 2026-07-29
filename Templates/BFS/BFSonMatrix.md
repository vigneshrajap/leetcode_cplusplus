# BFS on Matrix Template

## Overview

Many matrix problems are graph problems in disguise.
Each cell is a node, and edges connect adjacent cells.

BFS is ideal when you need minimum steps in an unweighted grid or level-by-level expansion.

Core pattern:

1. Put starting cell(s) in queue.
2. Mark visited (or mutate grid/state).
3. Pop a cell.
4. Try all valid neighbors.
5. Enqueue unvisited valid neighbors.

## Matrix as Graph Mapping

For an m x n grid:

- Node: coordinate (r, c)
- Edges: usually 4-direction neighbors (up, down, left, right)
- Optional edges: 8-direction or custom moves (knight moves, teleport, etc.)

Common direction vector:

```cpp
const std::vector<std::pair<int, int>> DIR4 = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};
```

## When to Use BFS on Matrix

- Shortest path by number of moves
- Multi-source expansion (rotting oranges, walls and gates)
- Flood fill by layers
- Minimum time/steps to reach target
- Region traversal where level distance matters

## Bounds Check Helper

```cpp
bool inBounds(int r, int c, int rows, int cols) {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}
```

## Single-Source BFS Template (Coordinate Version)

This version follows the coordinate-neighbor style directly.

```cpp
#include <queue>
#include <unordered_set>
#include <vector>

struct Coordinate {
    int row;
    int col;

    Coordinate(int r, int c) : row(r), col(c) {}

    bool operator==(const Coordinate& other) const {
        return row == other.row && col == other.col;
    }
};

struct CoordinateHash {
    std::size_t operator()(const Coordinate& p) const {
        return (static_cast<std::size_t>(p.row) << 32) ^ static_cast<std::size_t>(p.col);
    }
};

std::vector<std::vector<int>> grid;
int num_rows = static_cast<int>(grid.size());
int num_cols = num_rows == 0 ? 0 : static_cast<int>(grid[0].size());

std::vector<Coordinate> get_neighbors(Coordinate coord) {
    int row = coord.row;
    int col = coord.col;
    int delta_row[4] = {-1, 0, 1, 0};
    int delta_col[4] = {0, 1, 0, -1};

    std::vector<Coordinate> res;
    for (int i = 0; i < 4; i++) {
        int neighbor_row = row + delta_row[i];
        int neighbor_col = col + delta_col[i];

        if (0 <= neighbor_row && neighbor_row < num_rows &&
            0 <= neighbor_col && neighbor_col < num_cols) {
            res.emplace_back(Coordinate(neighbor_row, neighbor_col));
        }
    }
    return res;
}

void bfs(Coordinate starting_node) {
    std::queue<Coordinate> q;
    q.push(starting_node);

    std::unordered_set<Coordinate, CoordinateHash> visited;
    visited.emplace(starting_node);

    while (q.size() > 0) {
        Coordinate node = q.front();
        for (Coordinate neighbor : get_neighbors(node)) {
            if (visited.count(neighbor)) continue;

            // Do stuff with the node if required.
            q.push(neighbor);
            visited.emplace(neighbor);
        }
        q.pop();
    }
}
```

Note: initialize `num_rows` and `num_cols` after `grid` is loaded with actual data.

## Multi-Source BFS Template

Use this when many starts expand simultaneously and you want minimum distance/time from any source.

```cpp
#include <queue>
#include <vector>

std::vector<std::vector<int>> multiSourceDistance(
    const std::vector<std::vector<int>>& grid,
    const std::vector<std::pair<int, int>>& sources) {

    int rows = static_cast<int>(grid.size());
    if (rows == 0) return {};
    int cols = static_cast<int>(grid[0].size());

    const std::vector<std::pair<int, int>> DIR4 = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, -1));
    std::queue<std::pair<int, int>> q;

    for (auto [r, c] : sources) {
        if (!inBounds(r, c, rows, cols)) continue;
        if (grid[r][c] == 1) continue;
        if (dist[r][c] != -1) continue;
        dist[r][c] = 0;
        q.push({r, c});
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto [dr, dc] : DIR4) {
            int nr = r + dr;
            int nc = c + dc;

            if (!inBounds(nr, nc, rows, cols)) continue;
            if (grid[nr][nc] == 1) continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return dist;
}
```

## Layer-by-Layer BFS Template

Use queue size to process one BFS layer at a time.

```cpp
int minStepsByLayers(const std::vector<std::vector<int>>& grid,
                     int sr, int sc, int tr, int tc) {
    int rows = static_cast<int>(grid.size());
    if (rows == 0) return -1;
    int cols = static_cast<int>(grid[0].size());

    if (!inBounds(sr, sc, rows, cols) || !inBounds(tr, tc, rows, cols)) return -1;
    if (grid[sr][sc] == 1 || grid[tr][tc] == 1) return -1;

    const std::vector<std::pair<int, int>> DIR4 = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::queue<std::pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    int steps = 0;
    while (!q.empty()) {
        int layerSize = static_cast<int>(q.size());
        for (int i = 0; i < layerSize; ++i) {
            auto [r, c] = q.front();
            q.pop();

            if (r == tr && c == tc) return steps;

            for (auto [dr, dc] : DIR4) {
                int nr = r + dr;
                int nc = c + dc;
                if (!inBounds(nr, nc, rows, cols)) continue;
                if (grid[nr][nc] == 1) continue;
                if (visited[nr][nc]) continue;

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        ++steps;
    }

    return -1;
}
```

## Complexity

For an m x n matrix:

- Time: O(mn), each cell is processed at most once.
- Space: O(mn) for visited/dist and queue in worst case.

## Common Mistakes

- Missing boundary checks before grid access
- Marking visited too late (duplicate enqueues)
- Mixing row and column indices
- Forgetting blocked-cell checks
- Using DFS when shortest-by-moves answer is required
- Reusing mutable grid state across test cases unintentionally

## Quick Mental Checklist

- What represents blocked vs free cells?
- 4-direction, 8-direction, or custom moves?
- Single-source or multi-source BFS?
- Did I mark visited at enqueue time?
- Do I need distance array or just visited?
