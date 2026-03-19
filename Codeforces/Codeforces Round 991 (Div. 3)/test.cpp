#include <bits/stdc++.h>
using namespace std;
int main(){
    // freopen("in.txt", "r", stdin);
    freopen("std.txt", "w", stdout);
    int n = 2e5;
    string s = "";
    vector<int>k(5);
    k[0] = 1;
    k[1] = 3;
    k[2] = 5;
    k[3] = 7;
    k[4] = 9;
    for(int i =0 ;i < n;i ++){
        s.push_back(k[i%5] +'0');
    }


    cout << 1 << endl;
    cout << s << endl;
}