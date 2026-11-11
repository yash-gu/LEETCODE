class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long c1 = cost1;
        long long c2 = cost2;
        long long cb = costBoth;
        long long n1 = need1;
        long long n2 = need2;

        long long option1 = (n1 * c1) + (n2 * c2);

        long long common = min(n1, n2);
        long long rem1 = n1 - common;
        long long rem2 = n2 - common;
        long long option2 = (common * cb) + (rem1 * c1) + (rem2 * c2);

        long long option3 = max(n1, n2) * cb;

        return min({option1, option2, option3});
    }
};