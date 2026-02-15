class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0;
        int balanced_count = 0;

        for (char c : s) {
            // Update the running balance
            if (c == 'R') balance++;
            else balance--;

            // If balance is 0, we just completed a balanced substring
            if (balance == 0) {
                balanced_count++;
            }
        }

        return balanced_count;
    }
};