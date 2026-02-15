#include <string>
#include <algorithm>

class Solution {
public:
    int maximum69Number (int num) {
        // Convert to string to access digits easily
        std::string s = std::to_string(num);
        
        // Find the first occurrence of '6'
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '6') {
                s[i] = '9'; // Change it to '9'
                break;      // Only change the FIRST one (Greedy)
            }
        }
        
        // Convert back to integer
        return std::stoi(s);
    }
};