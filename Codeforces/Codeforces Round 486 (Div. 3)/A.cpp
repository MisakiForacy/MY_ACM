#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n,k,x;
    cin >> n >> k;
    vector<int> a;
    map<int,int> mp;
    for (int i = 1;i <= n;i ++){
        cin >> x;
        if (!mp.count(x)){
            a.push_back(i);
        }
        mp[x] ++;
    }
    if (a.size() < k){
        cout << "NO\n";
    } else{
        cout << "YES\n";
        for (int i = 0;i < k;i ++){
            cout << a[i] << " \n"[i == k - 1];
        }
    }
}