class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        int m = 1000000007;
        vector<long long> dp(n + 1, 1);
        bool k = 1;
        for (int i = d + 1; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - d]) % m;
            if (i > f) {
                dp[i] = (dp[i] - dp[i - f] + m) % m;
                if (k) {
                    dp[i] = (dp[i] + m - dp[i - f]) % m;
                    k = 0;
                }
            }
        }
        return dp[n];
    }
};
