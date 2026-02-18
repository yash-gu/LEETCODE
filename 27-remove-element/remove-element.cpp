class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;                  // next position to write
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {   // keep this element
                nums[k] = nums[i];
                k++;
            }
        }
        return k; // new length
    }
};
