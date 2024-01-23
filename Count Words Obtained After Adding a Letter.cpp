class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> s;
        for (auto x : startWords) {
            sort(x.begin(), x.end());
            s.insert(x);
        }
        int ans = 0;
        for (auto it : targetWords) {
            string temp = it;
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++) {
                string firstt = temp.substr(0, i);
                string secondd = temp.substr(i + 1);
                string check = firstt + secondd;
                if (s.find(check) != s.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
