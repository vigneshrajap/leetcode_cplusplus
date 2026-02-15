class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size()!=t.size()) return false;

        int count[26] = {0};

        for (char c:s){
            count[c-'a']++;
        }

        for (char c:t){
            count[c-'a']--;
            if (count[c-'a'] < 0) return false;
        }

        return true;        
    }
};