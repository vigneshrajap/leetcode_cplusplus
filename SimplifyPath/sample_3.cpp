#include <iostream>
#include <string>
#include <vector>
#include <string_view>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        // Stack stores lightweight string_views (pointers + lengths), NOT full std::strings
        std::vector<std::string_view> st;
        std::string_view sv(path);

        while (!sv.empty()) {
            size_t pos = sv.find('/');
            
            // Extract token up to '/' or the rest of the view
            std::string_view dir = (pos != std::string_view::npos) ? sv.substr(0, pos) : sv;

            // Process directory rules
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!st.empty()) {
                        st.pop_back();
                    }
                } else {
                    st.push_back(dir);
                }
            }

            // Advance string_view past processed token and '/'
            if (pos == std::string_view::npos) {
                break;
            }
            sv.remove_prefix(pos + 1);
        }

        // Reconstruct canonical string once at the end
        std::string result = "";
        for (std::string_view dir : st) {
            result += "/";
            result.append(dir.data(), dir.size());
        }

        return result.empty() ? "/" : result;
    }
};