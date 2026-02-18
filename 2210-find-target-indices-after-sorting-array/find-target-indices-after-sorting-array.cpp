class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                for (int b = mid; b >= 0 && nums[b] == target; b--) {
                    ans.push_back(b);
                }
                for (int a = mid + 1; a < nums.size() && nums[a] == target; a++) {
                    ans.push_back(a);
                }
                sort(ans.begin(), ans.end()); 
                return ans;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
