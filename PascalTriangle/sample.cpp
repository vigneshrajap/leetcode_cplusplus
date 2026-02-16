#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Initialize a vector of size (rowIndex + 1) with all 1s
        vector<int> res(rowIndex + 1, 1);

        // i is the current row we are simulating
        for (int i = 1; i < rowIndex; i++) {
            // Update the row backward from index (i) down to 1
            for (int j = i; j > 0; j--) {
                res[j] = res[j] + res[j - 1];
            }
        }
        
        return res;
    }
};