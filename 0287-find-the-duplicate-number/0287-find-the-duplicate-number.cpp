class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> vis;
        for(int i=0;i<nums.size();i++){
            if(vis.find(nums[i])!=vis.end()){
                return nums[i];
            }
            vis.insert(nums[i]);
        }
        return -1;
    }
};