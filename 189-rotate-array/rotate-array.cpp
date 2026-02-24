class Solution {
public:
    void reverseRange(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;  
        reverseRange(nums, 0, n - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
    }
};
