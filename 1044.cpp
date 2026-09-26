
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();

        long long mod = 1000000007;
        long long base = 26;

        auto search = [&](int len) -> int {
            long long hash = 0;
            long long power = 1;

            for (int i = 0; i < len; i++) {
                hash = (hash * base + (s[i] - 'a')) % mod;
                if (i < len - 1) {
                    power = (power * base) % mod;
                }
            }

            unordered_map<long long, vector<int>> seen;
            seen[hash].push_back(0);

            for (int i = len; i < n; i++) {
                hash = (hash - (s[i - len] - 'a') * power % mod + mod) % mod;
                hash = (hash * base + (s[i] - 'a')) % mod;

                int start = i - len + 1;

                if (seen.count(hash)) {
                    for (int prev : seen[hash]) {
                        if (s.compare(prev, len, s, start, len) == 0) {
                            return start;
                        }
                    }
                }

                seen[hash].push_back(start);
            }

            return -1;
        };

        int left = 1, right = n - 1;
        int bestStart = -1, bestLen = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int start = search(mid);

            if (start != -1) {
                bestStart = start;
                bestLen = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (bestStart == -1) {
            return "";
        }

        return s.substr(bestStart, bestLen);
    }
};
