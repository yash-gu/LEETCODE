class Solution {
    int sumsq(int n){
        int sq = 0;
    while (n) {
        int digit = n % 10;
        sq += digit * digit;
        n = n / 10;
    }
    return sq;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        vis.insert(n);

        while(true){
            if(n==1)return true;
            n=sumsq(n);
            if(vis.find(n)!=vis.end())return false;
            vis.insert(n);
        }

        return false;

    }
};