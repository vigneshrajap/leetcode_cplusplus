class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        // Even if there are "infinite" boxes, we only use a few.
        // For input up to 100,000, max sum is 9+9+9+9+9 = 45.
        // Using an array is faster than a map for these small ranges.
        int boxes[50] = {0}; 
        int max_count = 0;

        for (int i = lowLimit; i <= highLimit; i++) {
            int current_ball = i;
            int box_id = 0;
            
            // Calculate digit sum
            while (current_ball > 0) {
                box_id += current_ball % 10;
                current_ball /= 10;
            }
            
            // Increment the count for that box
            boxes[box_id]++;
            
            // Track the maximum on the fly
            if (boxes[box_id] > max_count) {
                max_count = boxes[box_id];
            }
        }

        return max_count;
    }
};