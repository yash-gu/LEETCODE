class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> ans_set;
        for(int i=0;i<n;i++){
            int complement = target-nums[i];
            if(ans_set.find(complement)!=ans_set.end()){
                return {ans_set[complement],i};
            }
            ans_set[nums[i]]=i;
        }
        return {};
    }
};