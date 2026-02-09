class Solution {
public:
    bool isselfDividing(int num){
            int value = num;
            while(num>0){
                int lastnum = num%10;
                if (lastnum==0 || value%lastnum!=0){
                    return false;
                }
                num /= 10;
            }
            return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {

        vector<int> result;

        for(int val=left; val<=right; val++) {     
            bool status = isselfDividing(val);
            if (status) result.push_back(val);
        }

        return result;
    }
};