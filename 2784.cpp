class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        // A good array must have n + 1 elements
        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // 1 to n-1 must appear exactly once
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        // n must appear exactly twice
        if (freq[n] != 2)
            return false;

        return true;
    }
};
