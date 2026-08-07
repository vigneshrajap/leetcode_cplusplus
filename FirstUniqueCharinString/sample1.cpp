class Solution {
public:
    int firstUniqChar(string s) {
        int freq_map[26] = {0};

        for(auto c:s){
            freq_map[c-'a']++;
        }
        
        for(auto i=0;i<s.size();i++){
            if(freq_map[s[i]-'a']==1) return i;
        }  

        return -1;
    }
};