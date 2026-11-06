class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        
        // 1. Find the total number of bits in num
        int temp = num;
        int bitCount = 0;
        while (temp > 0) {
            bitCount++;
            temp >>= 1;
        }
        
        // 2. Process from the highest bit (left) to the lowest bit (right)
        for (int i = bitCount - 1; i >= 0; i--) {
            // Extract the bit at position i and flip it
            int bit = !((num >> i) & 1);
            
            // Shift ans left and safely append the flipped bit
            ans = (ans << 1) | bit;
        }
        
        return ans;
    }
};