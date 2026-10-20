class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapi;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int com=target-nums[i];
            if(mapi.find(com)!=mapi.end()){
                return {mapi[com],i};
            }
            mapi[nums[i]] = i; 
        }
        return {};
    } 
};