#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    int cnt = 0;
    cin >> s;
    vector<int>idx;
    int len = s.length();
    for (int i=0;i<=len - 6;i++){
        if ("friend"==s.substr(i,6)){
            idx.push_back(i);
        }
    }
    int t = idx.size();
    for (int i=t-1;i>=0;i--){
        if (i>0 && idx[i]-idx[i-1]<=8){
            cnt += 1;
            i --;
        } else{
            cnt += 1;
        }
    }
    cout << cnt << '\n';
}