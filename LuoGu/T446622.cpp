#include <bits/stdc++.h>
using namespace std;

static vector<int>alpha(26);
static vector<int>mmaxn(26);
int dp(string str,int len);
// bool is_not_mode(string str);

int main(){
    string str;
    cin >> str;
    cout << dp(str,str.length());
}

int dp(string str,int len){
    static int maxn;
    if(str.length()==1){
        alpha[str[0] - 'a'] = 1;
        maxn = 1;
        return 0;
    }
    maxn = max(maxn,alpha[str[str.length()-1]] + dp(str.substr(0,str.length()-1),str.length()-1));
    return maxn;
}

// bool is_not_mode(string str){

// }