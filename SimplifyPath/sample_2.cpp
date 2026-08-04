#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st; // Use vector as a stack
        std::stringstream ss(path);
        std::string directory;

        // Step 1: Tokenize by '/'
        while (std::getline(ss, directory, '/')) {
            if (directory.empty() || directory == ".") {
                continue; // Skip empty tokens (from consecutive '//') and '.'
            }
            if (directory == "..") {
                if (!st.empty()) {
                    st.pop_back(); // Pop parent directory
                }
            } else {
                st.push_back(directory); // Push valid directory name
            }
        }

        // Step 2: Build final path directly from left to right
        std::string result = "";
        for (const std::string& dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};