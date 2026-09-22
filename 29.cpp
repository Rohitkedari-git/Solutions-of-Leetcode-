class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;

        // Keep taking the largest possible multiple of divisor
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Determine the sign
        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int)quotient;
    }
};
