class Solution {
public:
    int arrangeCoins(int n) {
        int l=1;
        int r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long num=(long long)mid*(mid+1)/2;
            if(num==n)return mid;
            else if(num<n)l=mid+1;
            else r=mid-1;
        }
        return r;
    }
};