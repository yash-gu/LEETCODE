class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        vector<int> check(n+1,0);
        for(int num:nums){
            check[num]+=1;
        }
        for(int i=1;i<=n;i++){
            if(check[i]==0) ans.push_back(i);
        }
        return ans;
    }
};