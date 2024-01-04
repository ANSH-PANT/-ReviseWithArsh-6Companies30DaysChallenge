class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
       int P = 201;
       int n = nums.size(), ans = 0;
       unordered_set<size_t> set; 
       for (int i = 0; i < n; ++i) {
           long long int hash = 0; 
           int cnt = 0;
           for (int j = i; j < n; ++j) {
               hash = hash * P + nums[j]; 
               cnt += (nums[j] % p == 0);
               if (cnt > k) break; 
               ans += set.insert(hash).second;
            }
        }
        return ans;
    }
};    
