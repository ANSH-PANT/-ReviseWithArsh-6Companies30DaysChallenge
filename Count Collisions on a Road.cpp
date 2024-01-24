class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        bool sl = false;
        int right = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (directions[i] == 'S') {
                sl = true;
                ans += right;
                right = 0;
            } else if (directions[i] == 'L') {
                if (right) {
                    right--;
                    ans += 2;
                    ans += right;
                    right = 0;
                    sl = true;
                } else if (sl) {
                    ans++;
                }
            } else {
                right++;
            }
        }
        return ans;
    }
};
