class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> lost;
        for (auto match : matches) {
            lost[match[0]] += 0;
            lost[match[1]]++;
        }
        vector<vector<int>> ans(2);
        for (auto keyval : lost) {
            if (keyval.second == 0)
                ans[0].push_back(keyval.first);
            else if (keyval.second == 1)
                ans[1].push_back(keyval.first);
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};
