class Solution {
public:
    
    bool is_point_on_circle(vector<int>& query, vector<int>& point){
        // Calculate squared distance components
        int dx = point[0] - query[0];
        int dy = point[1] - query[1];
        int radius = query[2];

        // Compare squared distance to squared radius
        if ((dx * dx + dy * dy) <= (radius * radius)) 
            return true;

        return false;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

    vector<int> answer(queries.size(), 0);

    for(size_t i=0;i<queries.size();i++){
        for(size_t j=0;j<points.size();j++){
            if (is_point_on_circle(queries[i], points[j])) answer[i]++;
        }
    }

    return answer;

    }
};