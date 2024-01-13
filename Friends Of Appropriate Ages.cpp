class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < ages.size(); i++) {
            if (!mp.count(ages[i]))
                mp[ages[i]] = i;
        }
        for (int i = 0; i < ages.size(); i++) {
            int x = lower_bound(ages.begin(), ages.end(), 2 * (ages[i] - 7)) -
                    ages.begin();
            if (x <= i)
                continue;
            ans += x - mp[ages[i]] - 1;
        }
        return ans;
    }
};
