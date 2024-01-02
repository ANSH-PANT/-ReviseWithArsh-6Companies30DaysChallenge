char ** letterCombinations(char * digits, int* returnSize){
    char ** ret;
    *returnSize = 0;
    if (*digits == '\0')    return NULL;
    char d = *digits;
    int size = 0;
    char comb[5];
    switch (d)    {
        case '2':    strcpy(comb, "abc");
            break;
        case '3':    strcpy(comb, "def");
            break;
        case '4':    strcpy(comb, "ghi");
            break;
        case '5':    strcpy(comb, "jkl");
            break;
        case '6':    strcpy(comb, "mno");
            break;
        case '7':    strcpy(comb, "pqrs");
            break;
        case '8':    strcpy(comb, "tuv");
            break;
        case '9':    strcpy(comb, "wxyz");    }
    int combLen = strlen(comb);
    char ** res = letterCombinations(digits + 1, &size);
    if (res)    {
        int len = strlen(res[0]) + 1;
        * returnSize = size * combLen;
        ret = malloc(sizeof(char*) * (* returnSize));
        int ri = 0;
        for (int i = 0; i < combLen; i++)    {
            for (int j = 0; j < size; j++)    {
                ret[ri] = malloc(sizeof(char) * (len + 1));
                ret[ri][0] = comb[i];
                strcpy(&ret[ri][1], res[j]);
                ri++;    }    }
        for (int i = 0; i < size; i++)
            free(res[i]);
        free(res);    }
    else    {
        ret = malloc(sizeof(char*) * combLen);
        for (int i = 0; i < combLen; i++)    {
            ret[i] = malloc(sizeof(char) * 2);
            ret[i][0] = comb[i];
            ret[i][1] = 0;    }
        * returnSize = combLen;    }
    return ret;}
