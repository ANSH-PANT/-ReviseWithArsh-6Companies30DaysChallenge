class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> ans;
        if (n < 10) {
            return ans;
        }
        unordered_map<string, int> ump;
        for (int i = 0; i < s.size() - 9; i++) {
            string t = s.substr(i, 10);
            ump[t]++;
        }
        for (auto it : ump) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
