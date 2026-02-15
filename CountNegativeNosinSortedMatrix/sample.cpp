class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int count = 0;

        for(int i = 0; i<m; i++){
            count += std::count_if(grid[i].begin(), grid[i].end(),[](int n){return n < 0;});
        }

        return count;
    }
};