class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3)return -1;
        int ans=nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-2;i++){
            int mid=i+1;
            int right=n-1;

            while(mid<right){
                int sum=nums[i]+nums[mid]+nums[right];
                if(abs(ans-target)>abs(sum-target)){
                    ans=sum;

                }
                if(sum==target){
                    return target;

                }else if(sum<target){
                    mid++;
                }else{
                    right--;
                }
            }

        }
        return ans;
    }
};