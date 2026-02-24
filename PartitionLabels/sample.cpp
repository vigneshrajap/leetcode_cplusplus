class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> result;
        int last_pos[26] = {0};

        for(int i=0;i<s.size();i++){
            last_pos[s[i]-'a'] = i;
        }


        int far_end = 0;
        int start_of_chunk = 0;

        for(int i=0;i<s.size();i++){
            far_end = std::max(far_end, last_pos[s[i]-'a']);

            if(i==far_end){
                result.push_back(i-start_of_chunk+1);
                start_of_chunk = i + 1;
            }

        }

        return result;

    }
};