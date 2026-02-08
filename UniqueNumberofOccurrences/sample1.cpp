#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Step 1: Count the frequency of each element in the array
        std::unordered_map<int, int> frequencyMap;
        for (int& element : arr) {
            ++frequencyMap[element];
        }
      
        // Step 2: Check if all frequencies are unique using a set
        std::unordered_set<int> seenFrequencies;
        for (auto& [key, frequency] : frequencyMap) {
            // If this frequency has already been seen, frequencies are not unique
            if (seenFrequencies.count(frequency)) {
                return false;
            }
            // Add the current frequency to the set of seen frequencies
            seenFrequencies.insert(frequency);
        }
      
        // All frequencies are unique
        return true;
    }
};
