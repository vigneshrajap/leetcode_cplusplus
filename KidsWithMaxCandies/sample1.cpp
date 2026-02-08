class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int max_candies = *std::max_element(candies.begin(), candies.end());
        vector<bool> kids;
        
        for(int val: candies){
            kids.push_back(val + extraCandies >= max_candies);
        }

        return kids;
    }
};