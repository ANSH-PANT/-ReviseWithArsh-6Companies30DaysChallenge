class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty()) {
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int h = p.second;
            int x[] = {-1, 0, 1, 0};
            int y[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nx = r + x[i];
                int ny = c + y[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    vis[nx][ny] == 0) {
                    ans[nx][ny] = h + 1;
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, h + 1});
                }
            }
        }
        return ans;
    }
};
