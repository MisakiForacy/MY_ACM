#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ask(int l,int r){
    cout << "? " << l << ' ' << r << '\n';
    int x;cin >> x;
    return x;
}
int main(){
    int n;
    cin >> n;
    int l = 1;
    vector<int> pre(n+1,0);
    vector<int> diff(n+1,0);
    for (int r=n;r>=2;r--){
        pre[r] = ask(l,r);
    }
    pre[1] = pre[3] - ask(2,3);
    for (int i=1;i<=n;i++){
        diff[i] = pre[i] - pre[i-1];
    }
    cout << "! ";
    for (int i=1;i<=n;i++){
        cout << diff[i] << " \n"[i==n];
    }
}