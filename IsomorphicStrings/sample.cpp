class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map <char, char> mapping_s_to_t;
        std::unordered_map <char, char> mapping_t_to_s;

        for (int i=0; i<s.size(); i++) 
        {
            if (mapping_s_to_t.contains(s[i]) && mapping_s_to_t[s[i]] != t[i]) return false;
            if (mapping_t_to_s.contains(t[i]) && mapping_t_to_s[t[i]] != s[i]) return false;
        
            mapping_s_to_t[s[i]] = t[i];
            mapping_t_to_s[t[i]] = s[i];
        }

        return true;
    }
};