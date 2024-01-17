class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,int cCenter) {
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                ans.push_back({i, j});
        }
        sort(ans.begin(), ans.end(), [&](auto& a, auto& b) {
            return (abs(rCenter - a[0]) + abs(cCenter - a[1]) <
                    abs(rCenter - b[0]) + abs(cCenter - b[1]));
        });
        return ans;
    }
};
