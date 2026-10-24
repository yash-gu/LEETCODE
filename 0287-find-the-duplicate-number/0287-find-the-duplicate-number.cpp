class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int correctidx=nums[i];
            if(nums[i]==i)continue;
            else{
                if (nums[correctidx] == nums[i]) {
                    return nums[i];
                }
                swap(nums[i], nums[correctidx]);
                i--;
            }

        }
        return -1;
    }
};