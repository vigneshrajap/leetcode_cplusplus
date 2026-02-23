class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 1. Initialize an n x n matrix with zeros
        vector<vector<int>> result(n, vector<int>(n, 0));
        
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int count = 1; // Use a counter to fill the values

        while (top <= bottom && left <= right) {
            // Traverse Right
            for (int i = left; i <= right; i++) {
                result[top][i] = count++;
            }
            top++;

            // Traverse Down
            for (int i = top; i <= bottom; i++) {
                result[i][right] = count++;
            }
            right--;

            // Traverse Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result[bottom][i] = count++;
                }
                bottom--;
            }

            // Traverse Up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result[i][left] = count++;
                }
                left++;
            }
        }

        return result;
    }
};