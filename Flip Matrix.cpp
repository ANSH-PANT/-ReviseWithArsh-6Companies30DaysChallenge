class Solution {
public:
    Solution(int m, int n) : rows(m), cols(n), total(m * n) {
    }
    vector<int> flip() {
        if (used.size() == total) return {};
        int index = rand() % total;
        while (used.count(index))
        index = ++index % total;
        used.insert(index);
        return {index / cols, index % cols};
    }
    void reset() {
        used.clear();
    }
 private:
    unordered_set<int> used;
    int rows;
    int cols;
    int total;
};
