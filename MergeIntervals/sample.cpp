class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        // 1. Sort by start time
        std::sort(intervals.begin(), intervals.end(), 
                [](const std::vector<int>& a, std::vector<int>& b){ return a[0] < b[0]; });

        std::vector<std::vector<int>> result;
        
        for(auto& interval: intervals){
            int start = interval[0];
            int end = interval[1];

            // 2. Overlap with the last kept interval?
            // Two intervals `[a.start,a.end]` and `[b.start,b.end]` do NOT overlap when
            // `a.end < b.start` or `b.end < a.start` (one is completely left of the other).
            // Negating that gives the positive overlap test used below:
            // they overlap iff `a.start <= b.end && b.start <= a.end`.
            // (See: https://algo.monster/interval_pattern_intro/overlap-condition.svg)
            if(!result.empty() && start<=result.back()[1]){
                // Merge: extend the end of the last interval
                result.back()[1] = std::max(end, result.back()[1]);
            }
            else{
                // 3. No overlap: keep this interval as-is
                result.push_back({start, end});
            }
            
        }
    
        return result;
    }
};