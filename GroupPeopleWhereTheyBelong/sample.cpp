class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> grps;
        vector<vector<int>> result;

        for(int i=0;i<groupSizes.size();i++){
            int size = groupSizes[i];
            grps[size].push_back(i);
            
            // If the group is full, move it to result and clear it
            if (grps[size].size() == size) {
                result.push_back(grps[size]);
                grps[size].clear();
            }
        }

        return result;
    }
};