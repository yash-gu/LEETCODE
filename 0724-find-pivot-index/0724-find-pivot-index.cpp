class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int suffix=0;
        for(int i=0;i<n;i++){
            suffix+=nums[i];
        }
        int prefix=0;
        for(int i=0;i<n;i++){
            suffix-=nums[i];
            if(suffix==prefix)return i;
            prefix+=nums[i];
        }
        return -1;
        
    }
};