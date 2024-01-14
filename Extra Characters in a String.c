int memo[51][51];
int findMaxLen(char* s, char** dict, int sPos, int wordNum, int wSize,
               int sSize) {
    if (sPos == sSize)
        return 0;
    if (memo[sPos][wordNum] != -1)
        return memo[sPos][wordNum];
    if (wordNum == wSize) {
        memo[sPos][wordNum] = findMaxLen(s, dict, sPos + 1, 0, wSize, sSize);
        return memo[sPos][wordNum];
    }
    int len = strlen(dict[wordNum]);
    if (strncmp(&(s[sPos]), dict[wordNum], len) == 0) {
        int path1 = len + findMaxLen(s, dict, sPos + len, 0, wSize, sSize);
        int path2 = findMaxLen(s, dict, sPos, wordNum + 1, wSize, sSize);
        memo[sPos][wordNum] = fmax(path1, path2);
        return memo[sPos][wordNum];
    } else {
        return findMaxLen(s, dict, sPos, wordNum + 1, wSize, sSize);
    }
}
int minExtraChar(char* s, char** dictionary, int dictionarySize) {
    memset(memo, -1, sizeof(memo));
    return strlen(s) -
           findMaxLen(s, dictionary, 0, 0, dictionarySize, strlen(s));
}
