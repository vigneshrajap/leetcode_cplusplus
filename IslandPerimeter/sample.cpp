#include <vector>
#include <queue>
#include <array>

using namespace std;
class Solution {
public:
    struct Coordinate{
        int r;
        int c;
        Coordinate(int r, int c): r{r}, c{c} {}
    };

    std::vector<Coordinate> get_neighbors(Coordinate cell, int num_rows, int num_cols) {
        std::vector<Coordinate> neighbors;
        std::array<int, 4> delta_row = {-1, 0, 1, 0};
        std::array<int, 4> delta_col = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int neighbor_row = cell.r + delta_row[i];
            int neighbor_col = cell.c + delta_col[i];
            if (0 <= neighbor_row && neighbor_row < num_rows && 0 <= neighbor_col && neighbor_col < num_cols) {
                neighbors.emplace_back(neighbor_row, neighbor_col);
            }
        }
        return neighbors;
    }

    void bfs(std::vector<std::vector<int>>& grid, Coordinate root, int num_rows, int num_cols, vector<vector<bool>>& visited, int& sides) {
        std::queue<Coordinate> q;
        q.push(root);
        visited[root.r][root.c] = true;

        while (!q.empty()) {
            Coordinate node = q.front();
            std::vector<Coordinate> neighbors = get_neighbors(node, num_rows, num_cols);
            sides += (4 - neighbors.size());

            for (Coordinate neighbor : neighbors) {
                // If the neighbor is water, it contributes an edge to our perimeter
                if (grid[neighbor.r][neighbor.c] == 0) {
                    sides++;
                } 
                // If it's land and we haven't visited it yet, queue it up
                else if (!visited[neighbor.r][neighbor.c]) {
                    visited[neighbor.r][neighbor.c] = true;
                    q.push(neighbor);
                }
            }

            q.pop();
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int perimeter_count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        // bfs starting from each unvisited land cell
        for (int r = 0; r < num_rows; r++) {
            for (int c = 0; c < num_cols; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;
                int sides = 0;
                bfs(grid, Coordinate(r, c), num_rows, num_cols, visited, sides);
                // bfs would find 1 connected island, increment count
                perimeter_count +=  sides;
            }
        }
        return perimeter_count;
    }
};