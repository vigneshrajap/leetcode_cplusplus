class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sorting is key!

        for(int i=0;i<nums.size();i++){
            // Skip the same element to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_map<int, int> freq_map;

            for(int j=i+1;j<nums.size();j++){
                if(freq_map.count(-nums[i]-nums[j])){
                    result.push_back({nums[i], nums[j], -nums[i]-nums[j]});
                }
                freq_map[nums[j]]++;
            }
        }
        return result;
    }
};