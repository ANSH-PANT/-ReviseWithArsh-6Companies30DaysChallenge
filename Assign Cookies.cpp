class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int nChildren = g.size();
        int nCookies = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int contentChildren = 0;
        int child = 0, cookie = 0;
        while(child < nChildren && cookie < nCookies) {
            if(g[child] <= s[cookie]) {
                // the child get the cookie
                ++contentChildren;
                child++;
                cookie++;
            } else {
                cookie++; // ignore the cookie
            }
        }
        return contentChildren;
    }
};
