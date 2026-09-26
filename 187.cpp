
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> repeated;
        vector<string> ans;

        for (int i = 0; i <= (int)s.size() - 10; i++) {
            string sub = s.substr(i, 10);

            if (seen.find(sub) != seen.end()) {
                if (repeated.find(sub) == repeated.end()) {
                    ans.push_back(sub);
                    repeated.insert(sub);
                }
            } else {
                seen.insert(sub);
            }
        }

        return ans;
    }
};
