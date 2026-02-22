class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> user_minutes;
        vector<int> result(k,0);

        for (auto& log : logs) {
            int user_id = log[0];
            int minute = log[1];
            user_minutes[user_id].insert(minute);
        }

        for(auto& [user, minutes]: user_minutes){
            int UAM = minutes.size();

            result[UAM-1]++;
        }

        return result;
    }
};