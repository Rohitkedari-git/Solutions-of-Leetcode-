class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;

        for (int num : nums) {
            string s = to_string(num);

            for (char c : s) {
                answer.push_back(c - '0');
            }
        }

        return answer;
    }
};
