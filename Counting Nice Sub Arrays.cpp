class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto& num : nums)
            if (num % 2)
                num = 1;
            else
                num = 0;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for (auto num : nums) {
            sum += num;
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};
