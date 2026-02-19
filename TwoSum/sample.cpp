class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> result;

        for(int i=0; i<nums.size(); i++){
            if (result.count(target-nums[i])){
                return {result[i], i};
            }
            result[nums[i]] = i;
        }

        return {};
    }
};