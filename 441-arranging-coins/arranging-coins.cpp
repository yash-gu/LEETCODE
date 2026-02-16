class Solution {
public:
    int arrangeCoins(int n) {
        int i=0;
        int c;
        while((long long)i*(i+1)/2<=n){
            c=i;
            i++;
        }
        return c;    
    }
};