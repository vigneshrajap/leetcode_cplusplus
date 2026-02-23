class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        if (matrix.empty()) return {};

        std::vector<int> result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while(top<=bottom && left<=right){
            // Transvere whole Row
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            // Transvere whole column
            for(int j=top;j<=bottom;j++){
                result.push_back(matrix[j][right]);
            }
            right--;

            // Transvere left (back)
            if(top<=bottom){
                for(int k=right;k>=left;k--){
                    result.push_back(matrix[bottom][k]);
                }
                bottom--;
            }

            // Transvere up (back)
            if(left<=right){
                for(int p=bottom;p>=top;p--){
                    result.push_back(matrix[p][left]);
                }
            left++;
            }

        }

      return result;
    }
};