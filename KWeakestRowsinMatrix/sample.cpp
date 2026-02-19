class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i=0; i<mat.size(); i++){
            int count = std::count(mat[i].begin(),mat[i].end(), 1);
            pq.push({count, i});
        }

        while(!pq.empty() && k>0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;

    }
};