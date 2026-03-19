#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s,ans;
    cin >> s >> n;
    int lo = 0, hi = n;
    if (n<s.length()){
        for (int i=0;i<s.length()-n;i++){
            int mi = 10;
            for (int j=lo;j<=hi;j++){
                if (s[j]-'0' < mi){
                    mi = s[j] - '0';
                    lo = j;
                }
            }
            ans.push_back(s[lo]);
            hi ++;
            lo ++;
        }
        cout << stoi(ans) << '\n';
    } else{
        cout << 0 << '\n';
    }
}