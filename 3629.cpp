class Solution {
public:
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            factors.push_back(x);

        return factors;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;

        // Find maximum value
        int maxVal = *max_element(nums.begin(), nums.end());

        // Sieve: isPrime[x] tells whether x is prime
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = false;

        if (maxVal >= 1)
            isPrime[1] = false;

        for (int i = 2; i * i <= maxVal; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // primeIndices[p] = indices whose values are divisible by p
        vector<vector<int>> primeIndices(maxVal + 1);

        for (int i = 0; i < n; i++) {
            vector<int> factors = getPrimeFactors(nums[i]);

            for (int p : factors) {
                primeIndices[p].push_back(i);
            }
        }

        // BFS
        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        // Prevent processing the same prime multiple times
        vector<bool> usedPrime(maxVal + 1, false);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            int d = dist[i];

            if (i == n - 1)
                return d;

            // Move left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = d + 1;
                q.push(i - 1);
            }

            // Move right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = d + 1;
                q.push(i + 1);
            }

            // Prime teleportation
            if (isPrime[nums[i]]) {
                int p = nums[i];

                if (!usedPrime[p]) {
                    usedPrime[p] = true;

                    for (int j : primeIndices[p]) {
                        if (dist[j] == -1) {
                            dist[j] = d + 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
