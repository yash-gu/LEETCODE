class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long left_val = (mid > 0) ? nums[mid - 1] : LLONG_MIN;
            long long right_val = (mid < nums.size() - 1) ? nums[mid + 1] : LLONG_MIN;
            
            if (nums[mid] > left_val && nums[mid] > right_val) {
                return mid;
            } else if (nums[mid] > left_val && nums[mid] < right_val) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};