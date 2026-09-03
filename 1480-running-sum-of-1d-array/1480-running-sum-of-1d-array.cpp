class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int prefix=0;
        for(int i=0;i<n;i++){
            ans[i]=nums[i]+prefix;
            prefix+=nums[i];
        }
        return ans;
    }
};