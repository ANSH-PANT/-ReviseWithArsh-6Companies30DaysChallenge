bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool dp[n + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < wordDictSize; j++) {
            int word_len = strlen(wordDict[j]);
            if (i >= word_len && dp[i - word_len] &&
                strncmp(&s[i - word_len], wordDict[j], word_len) == 0) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}
