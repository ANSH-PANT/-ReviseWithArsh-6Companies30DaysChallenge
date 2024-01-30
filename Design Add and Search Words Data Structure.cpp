struct Trie {
    Trie* ch[26];
    bool isEnd;
    Trie() {
        for (int i = 0; i < 26; i++)
            ch[i] = NULL;
        isEnd = false;
    }
};
bool find(string& str, int index, Trie* root) {
    if (index == str.length()) {
        return root->isEnd;
    }
    int k = str[index] - 'a';
    if (str[index] == '.') {
        for (int i = 0; i < 26; i++) {
            if (root->ch[i]) {
                bool l = find(str, index + 1, root->ch[i]);
                if (l)
                    return true;
            }
        }
    } else if (root->ch[k])
        return find(str, index + 1, root->ch[k]);
    return false;
}
class WordDictionary {
public:
    Trie* root;
    WordDictionary() { root = new Trie(); }
    void addWord(string word) {
        Trie* root1 = root;
        for (int i = 0; i < word.length(); i++) {
            int k = word[i] - 'a';
            if (!root1->ch[k])
                root1->ch[k] = new Trie();
            root1 = root1->ch[k];
        }
        root1->isEnd = true;
    }
    bool search(string word) { return find(word, 0, root); }
};
