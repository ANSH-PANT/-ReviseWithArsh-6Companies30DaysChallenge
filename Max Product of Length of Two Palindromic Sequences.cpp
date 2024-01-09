class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
    int maxProduct(int i, string s1, string s2, string& s) {
        if (i == s.size()) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                return (s1.size()) * (s2.size());
            }
            return 0;
        }
        int notTake = maxProduct(i + 1, s1, s2, s);
        int take1 = maxProduct(i + 1, s1 + s[i], s2, s);
        int take2 = maxProduct(i + 1, s1, s2 + s[i], s);
        return max({notTake, take1, take2});
    }
    int maxProduct(string s) { return maxProduct(0, "", "", s); }
};
