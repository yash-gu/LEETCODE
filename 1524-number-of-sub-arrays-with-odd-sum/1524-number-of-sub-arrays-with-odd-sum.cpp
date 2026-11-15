class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long oddCount = 0;
        long long evenCount = 1; // Represents the empty prefix sum of 0 (which is even)
        long long currentSum = 0;
        long long result = 0;

        for (int num : arr) {
            currentSum += num;

            if (currentSum % 2 == 0) {
                // Even prefix sum minus any previous odd prefix sum yields an odd subarray sum
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {
                // Odd prefix sum minus any previous even prefix sum yields an odd subarray sum
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }

        return result;
    }
};
