class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < nums.size(); i++)
            v.push_back({i, nums[i]});
        
        sort(v.begin(), v.end(), [&](auto a, auto b) {
            return a.second > b.second;
        });
        
        sort(v.begin(), v.begin() + k);
        
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(v[i].second);
        
        return res;
    }
};
