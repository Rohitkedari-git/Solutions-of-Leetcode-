
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (repeated.find(b) != string::npos) {
            return count;
        }

        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
    }
};
