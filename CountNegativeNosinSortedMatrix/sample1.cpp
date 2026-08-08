class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        int row = m - 1, col = 0;
        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                count += (n - col);  // everything to the right is also negative
                row--;
            } else {
                col++;
            }
        }
        return count;
    }
};