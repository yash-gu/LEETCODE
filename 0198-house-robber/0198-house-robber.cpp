class Solution {
    int fun(int n,vector<int>& dp,vector<int>& nums){
        if(n==0)return 0;
        if(n==1)return dp[1]=nums[0];
        if(n==2)return dp[2]=max(nums[0],nums[1]);
        if(dp[n]!=-1) return dp[n];
        dp[n]=max(fun(n-1,dp,nums),fun(n-2,dp,nums)+nums[n-1]);
        
        return dp[n];


    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0;
        vector<int> dp(n+1,-1);


        
        return fun(n,dp,nums);
    }
};