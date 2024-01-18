class Solution {
private:
    bool isSubsequence(const std::string& x, const std::string& y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.length();
    }

public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string max_str = "";
        for (const std::string& str : dictionary) {
            if (isSubsequence(str, s)) {
                if (str.length() > max_str.length() ||
                    (str.length() == max_str.length() && str < max_str))
                    max_str = str;
            }
        }
        return max_str;
    }
};
