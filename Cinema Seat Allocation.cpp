class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {

        int i = 0, count = 0, prev = 0;
        sort(rs.begin(), rs.end());
        vector<int> v;
        count += 2 * (n - rs[rs.size() - 1][0]);
        while (i < rs.size()) {
            v = vector<int>(10, 1);
            int rownum = rs[i][0];
            if ((prev + 1) != rownum)
                count += 2 * (rownum - prev - 1);
            prev = rownum;
            while (i < rs.size() && rs[i][0] == rownum) {
                v[rs[i][1] - 1] = 0;
                i++;
            }
            int c1 = v[1] & v[2] & v[3] & v[4] & v[5] & v[6] & v[7] & v[8];
            int c2 = (v[1] && v[2] && v[3] && v[4]) |
                     (v[3] & v[4] & v[5] & v[6]) | (v[5] & v[6] & v[7] & v[8]);

            if (c1)
                count += 2;
            else if (c2)
                count += 1;
        }
        return count;
    }
};
