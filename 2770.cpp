class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);

        // Starting position
        dp[0] = 0;

        for (int i = 0; i < n; i++) {

            // If index i cannot be reached
            if (dp[i] == -1)
                continue;

            for (int j = i + 1; j < n; j++) {

                long long diff = (long long)nums[j] - nums[i];

                // Check whether jump i -> j is valid
                if (abs(diff) <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
