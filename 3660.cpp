class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        vector<int> prefixMax(n);

        // Step 1: Calculate prefix maximum
        prefixMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        // Step 2: Scan from right to left
        int suffixMin = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {

            if (prefixMax[i] > suffixMin) {
                ans[i] = ans[i + 1];
            }
            else {
                ans[i] = prefixMax[i];
            }

            // Include nums[i] in suffix minimum
            suffixMin = min(suffixMin, nums[i]);
        }

        return ans;
    }
};
