class Solution {
public:
    vector<string>
    findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> m;
        for (auto& a : access_times) {
            int t = stoi(a[1]);
            m[a[0]].push_back(t / 100 * 60 + t % 100);
        }
        vector<string> res;
        for (auto& p : m) {
            auto& t = p.second;
            sort(t.begin(), t.end());
            for (int j = 2; j < t.size(); j++) {
                if (t[j] - t[j - 2] < 60) {
                    res.push_back(p.first);
                    break;
                }
            }
        }
        return res;
    }
};
