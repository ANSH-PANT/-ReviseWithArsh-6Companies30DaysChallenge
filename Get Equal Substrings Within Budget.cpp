class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currCost = 0;
        int len = s.length();
        int low = 0;
        int max_len = 0;
        for (int i = 0; i < len; i++) {
            currCost += abs(s[i] - t[i]);
            while (low <= i && currCost > maxCost) {
                currCost -= abs(s[low] - t[low]);
                low++;
            }
            max_len = max(max_len, i - low + 1);
        }
        return max_len;
    }
};
