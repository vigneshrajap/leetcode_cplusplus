class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<pair<int,int>> strength(rows); // (soldier count, row index)
        
        for (int i = 0; i < rows; i++) {
            int lo = 0, hi = cols;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (mat[i][mid] == 1) lo = mid + 1;
                else hi = mid;
            }
            strength[i] = {lo, i};
        }
        
        sort(strength.begin(), strength.end());
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(strength[i].second);
        }
        
        return result;
    }
};