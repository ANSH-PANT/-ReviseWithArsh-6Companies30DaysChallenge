#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    int power(ll x, ll times) {
        if (times == 0) {
            return 1;
        }
        ll temp = power(x, times / 2);
        temp = (temp * temp) % mod;
        if (times % 2) {
            temp = (temp * (x % mod)) % mod;
        }
        return temp % mod;
    }
    int minNonZeroProduct(int p) {
        ll x = (1ll << p) - 1;
        return x % mod * power(x - 1, x / 2) % mod;
    }
};
