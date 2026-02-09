#include <string>
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        int LastDigit;

        if (n==0) return 0;

        while(n>0){
            LastDigit = n%10; // Last number
            
            product *= LastDigit;
            sum += LastDigit;

            n /= 10; // Remaining numbers
        }

        int result = product - sum;
        return result;
    }
};