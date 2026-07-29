class Solution {
public:
    int reverseBits(int n) {     
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1; // Extract last bit
            result = (result << 1) | bit; // Left shift the empty result and add the last bit 
            n >>= 1; // Right Shift the n by one bit
        }
        return result;
    }
};