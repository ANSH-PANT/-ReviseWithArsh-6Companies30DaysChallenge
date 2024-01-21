class ThroneInheritance {
public:
    unordered_map<string, vector<string>> map;
    unordered_set<string> dead;
    string nameOfKing;
    ThroneInheritance(string kingName) { 
      nameOfKing = kingName;
    }
    void birth(string parentName, string childName) {
        map[parentName].push_back(childName);
    }
    void death(string name) { 
      dead.insert(name); 
    }
    void helper(string par, vector<string>& ans) {
        if (dead.count(par) == 0)
            ans.push_back(par);
        for (auto child : map[par])
            helper(child, ans);
    }
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        helper(nameOfKing, ans);
        return ans;
    }
};
