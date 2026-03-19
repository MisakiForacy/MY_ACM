#include <bits/stdc++.h>
using namespace std;
bool coprime(int n,int m){
    if (min(n,m)==1) return 1;
    for (int i=2;i<=min(n,m)&&i<=sqrt(max(n,m));i++){
        if (min(n,m)%i==0&&max(n,m)%i==0){
            return 0;
        }
    }
    return 1;
}
int main(){
    int s,x;
    cin >> s >> x;
    int ans = s;
    vector<int>a;
    while (ans){
        if (coprime(ans,x)){
            a.push_back(ans);
            ans = s - ans;
            s = ans;
            continue;
        }
        ans --;
    }
    cout << a.size() << '\n';
    for (int i=0;i<a.size();i++){
        cout << a[i] << " \n"[i==a.size()-1];
    }
}