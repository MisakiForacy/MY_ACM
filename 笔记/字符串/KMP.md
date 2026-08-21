# KMP

```cpp
vector<int> kmp(string t,string s){
    string str = t + '\0' + s;
    vector<int> pi(str.size(),0);
    for (int i=1;i<str.size();i++){
        int len = pi[i-1];
        while (len != 0 && str[i] != str[len]){
            len = pi[len - 1];
        }
        pi[i] = len + (str[i] == str[len]);
    }
    return pi;  // 最长前后缀匹配
}
```
a b c # a b c a b c d a b 
0 0 0 0 1 2 3 1 2 3


baabaa.0

aabaabaabaa
     