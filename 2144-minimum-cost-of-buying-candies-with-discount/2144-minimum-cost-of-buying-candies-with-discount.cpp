class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int sum=0;
        for(int i=0;i<cost.size();i++){
            int n=i+1;
            if(n%3==0)continue;
            sum+=cost[i];

        }
        return sum;
    }
};