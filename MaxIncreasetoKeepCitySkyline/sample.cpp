class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> row_max(n, 0);
        std::vector<int> col_max(n, 0);
        int total_sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                row_max[i] = max(row_max[i], grid[i][j]);
                col_max[j] = max(col_max[j], grid[i][j]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                total_sum += (min(row_max[i], col_max[j])-grid[i][j]);        
            }
        }

        return total_sum;
    }
};