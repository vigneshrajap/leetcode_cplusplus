#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Does this paper have at least (n - mid) citations?
            // (n - mid) represents the number of papers from index 'mid' to n-1
            if (citations[mid] >= n - mid) {
                // If yes, this could be our h-index, but try a smaller index 
                // to find an even larger h-index (since h = n - index)
                right = mid - 1;
            } else {
                // Citation count is too low, move to the right
                left = mid + 1;
            }
        }

        // After the loop, 'left' points to the first index where citations[i] >= n - i
        return n - left;
    }
};