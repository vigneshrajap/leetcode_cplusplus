lass Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Track the count of $5 and $10 bills we have for making change
        int fiveDollarCount = 0;
        int tenDollarCount = 0;
      
        // Process each customer's payment
        for (int bill : bills) {
            if (bill == 5) {
                // Customer pays with $5, no change needed
                fiveDollarCount++;
            } 
            else if (bill == 10) {
                // Customer pays with $10, need to give $5 change
                tenDollarCount++;
                fiveDollarCount--;
            } 
            else {  // bill == 20
                // Customer pays with $20, need to give $15 change
                if (tenDollarCount > 0) {
                    // Prefer to give one $10 and one $5
                    tenDollarCount--;
                    fiveDollarCount--;
                } else {
                    // Give three $5 bills as change
                    fiveDollarCount -= 3;
                }
            }
          
            // Check if we have enough bills to make change
            if (fiveDollarCount < 0) {
                return false;
            }
        }
      
        return true;
    }
};