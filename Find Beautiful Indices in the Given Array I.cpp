class Solution {
public:
    vector<int> beautifulIndices(vector<string>& words, string s, string t, int k) {
        const int n = words.size();
        vector<int> r;
        for (int i = 0; i < n; ++i) {
            if (words[i] == s) {
                for (int j = max(i - k, 0); j <= min(i + k, n - 1); ++j) {
                    if (words[j] == t) {
                        r.push_back(i);
                        break;
                    }
                }
            }
        }
        return r;
    }
};
