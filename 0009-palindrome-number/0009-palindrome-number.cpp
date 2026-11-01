class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        long long r = 0; 
        int temp = x;
        while (temp) {
            r = r * 10 + temp % 10;
            temp = temp / 10;
        }
        return x == r;
    }
};
