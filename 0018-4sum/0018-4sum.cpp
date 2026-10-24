class Solution {
public:
    vector<vector<int>> ans;

    void TwoSum(vector<int> &nums,int target,int i,int j,int n1,int n2){
        while(i<j){
            long long sum = (long long)n1+n2+nums[i]+nums[j];
            if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
            else{
                ans.push_back({n1,n2,nums[i],nums[j]});
                while(i<j && nums[i] == nums[i+1]){
                    i++;
                }
                while(i<j && nums[j] == nums[j-1]){
                    j--;
                }
                
                i++;
                j--;
            }
        }
    }

    void ThreeSum(vector<int> &nums,int target,int i,int j,int n1){
        for(int k=i;k<j-1;k++){
            if(k>i && nums[k]==nums[k-1]){
                continue;
            }
            int n2 = nums[k];
            TwoSum(nums,target,k+1,j,n1,n2);
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n<4){
            return {};
        }
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            ThreeSum(nums,target,i+1,n-1,n1);
        }
        return ans;
    }
};