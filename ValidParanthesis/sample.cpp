class Solution {
public:
    bool isValid(string s) {
    std::stack<char> st;
    std::unordered_map<char, char> pairs = {
        {')', '('}, {'}', '{'}, {']', '['}
    };
    for (char c : s) {
        if (pairs.count(c)) {
            if (st.empty() || st.top() != pairs[c]) {
                return false;
            }
            st.pop();
        } else {
            st.push(c);
        }
    }
    return st.empty();
};