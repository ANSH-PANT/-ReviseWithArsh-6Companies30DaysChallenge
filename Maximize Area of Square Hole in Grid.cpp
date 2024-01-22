class Solution {
private:
    int getMaxGap(vector<int> bars) {
        sort(bars.begin(), bars.end());
        int count = 2, res = 2;
        for (int i = 1; i < bars.size(); ++i) {
            count = (bars[i - 1] + 1 == bars[i]) ? count + 1 : 2;
            res = max(res, count);
        }
        return res;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,vector<int>& vBars) {
        int ans = min(getMaxGap(hBars), getMaxGap(vBars));
        return ans * ans;
    }
};
