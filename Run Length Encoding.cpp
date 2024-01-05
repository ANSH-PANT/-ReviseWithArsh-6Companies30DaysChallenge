string encode(string src)
{     
  int n = src.length(); 
  if (n == 0) {
    return ""; 
  }
  string result = "";
  for (int i = 0; i < n; i++) {
    int count = 1;
    while (i < n - 1 && src[i] == src[i+1]) {
      count++;
      i++;
    }
    result += src[i] + to_string(count); 
  }
  return result;
}
