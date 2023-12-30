class Solution {
public:
    long long int gcd(long long int a, long long int b) { return __gcd(a, b); }
    long long int lcm(long long int a, long long int b) {
        return (a * b) / gcd(a, b);
    }
    long long int getUniqueNumbersNotDivisibleBy(long long int d,
                                                 long long int n) {
        return n - (n / d);
    }
    bool isGood(int d1, int d2, int n, int cnt1, int cnt2) {
        int one = getUniqueNumbersNotDivisibleBy(d1, n);
        int two = getUniqueNumbersNotDivisibleBy(d2, n);
        int both = getUniqueNumbersNotDivisibleBy(lcm(d1, d2), n);
        int NotDivOnlyByOne = both - two;
        int NotDivOnlyByTwo = both - one;
        cnt1 = max(0, cnt1 - NotDivOnlyByOne);
        cnt2 = max(0, cnt2 - NotDivOnlyByTwo);
        return cnt1 + cnt2 <= both - NotDivOnlyByOne - NotDivOnlyByTwo;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        long long int ans = INT_MAX;
        long long int beg = 1, end = INT_MAX;
        while (beg <= end) {
            long long int mid = (beg + end) / 2;
            if (isGood(divisor1, divisor2, mid, uniqueCnt1, uniqueCnt2)) {
                ans = mid;
                end = mid - 1;
            } else
                beg = mid + 1;
        }
        return ans;
    }
};
