class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0; 
        
        int temp = abs(x);
        int ans = 0;
        while (temp > 0) {
            int digit = temp % 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
            
            ans = ans * 10 + digit;
            temp = temp / 10;
        }
        if (x < 0) {
            ans = ans * (-1);
        }
        return ans;
    }
};