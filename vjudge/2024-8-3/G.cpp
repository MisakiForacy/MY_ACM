#include <bits/stdc++.h>
using namespace std;
int main(){
    int w,b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    for (int i=0;i<5;i++){
        s.append(s);
    }
    vector<int>pre_w(500,0),pre_b(500,0);
    for (int i=0;i<s.length();i++){
        if (s[i]=='w'){
            pre_w[i] ++;
        } else{
            pre_b[i] ++;
        }
        pre_w[i] = pre_w[i-1] + pre_w[i];
        pre_b[i] = pre_b[i-1] + pre_b[i];
    }
    int lo,hi,ok = 0;
    for (hi=1;hi<500;hi++){
        for (lo=0;lo<hi;lo++){
            if (pre_w[hi]-pre_w[lo]==w&&pre_b[hi]-pre_b[lo]==b){
                ok = 1;
            }
        }
    }
    cout << (ok?"Yes\n":"No\n");
    // cout << s << '\n';
}