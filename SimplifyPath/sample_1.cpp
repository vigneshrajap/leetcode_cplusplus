#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> s;

        // Helper lambda to process a single directory token
        auto processDirectory = [&](const std::string& directory) {
            if (directory.empty() || directory == ".") {
                return; // Skip empty tokens and current directory markers
            }
            if (directory == "..") {
                if (!s.empty()) {
                    s.pop(); // Go to parent directory
                }
            } else {
                s.push(directory); // Push valid directory or file name
            }
        };

        size_t pos = 0;
        // Step 1: Process tokens separated by '/'
        while ((pos = path.find('/')) != std::string::npos) {
            processDirectory(path.substr(0, pos));
            path.erase(0, pos + 1);
        }

        // Step 2: Process the final token remaining after the last '/'
        processDirectory(path);

        // Step 3: Reconstruct the canonical path string from the stack
        std::string result = "";
        while (!s.empty()) {
            result = '/' + s.top() + result;
            s.pop();
        }

        // Step 4: Fallback to "/" if path is empty
        return result.empty() ? "/" : result;
    }
};