class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        auto res = img;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int deno = 1;
                if(i > 0) {
                    if(j > 0) {
                        res[i][j] += img[i-1][j-1];
                        deno++;
                    }
                    res[i][j] += img[i-1][j];
                    deno++;
                    if(j < n-1) {
                        res[i][j] += img[i-1][j+1];
                        deno++;
                    }
                }
                if(i < m-1) {
                    if(j > 0) {
                        res[i][j] += img[i+1][j-1];
                        deno++;
                    }
                    res[i][j] += img[i+1][j];
                    deno++;
                    if(j < n-1) {
                        res[i][j] += img[i+1][j+1];
                        deno++;
                    }
                }
                if(j > 0) {
                    res[i][j] += img[i][j-1];
                    deno++;
                }
                if(j < n-1) {
                    res[i][j] += img[i][j+1];
                    deno++;
                }
                res[i][j] /= deno;
            }
        }
        return res;
    }
};
