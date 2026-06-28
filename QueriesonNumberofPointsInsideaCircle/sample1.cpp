class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // Step 1: Preprocess by sorting points based on X-coordinate
        sort(points.begin(), points.end());
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& query : queries) {
            int cx = query[0], cy = query[1], r = query[2];
            int r_squared = r * r;
            int count = 0;
            
            // Step 2: Binary search for the first point where x >= cx - r
            auto it = lower_bound(points.begin(), points.end(), vector<int>{cx - r, 0});
            
            // Step 3: Scan linearly only while x is within bounds
            for (; it != points.end(); ++it) {
                int x = (*it)[0];
                int y = (*it)[1];
                
                // If x goes beyond the circle's right edge, we can safely stop completely
                if (x > cx + r) break; 
                
                // Fast squared distance check for the Y-axis component
                if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r_squared) {
                    count++;
                }
            }
            answer.push_back(count);
        }
        
        return answer;
    }
};