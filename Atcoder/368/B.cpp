#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=0;i<n;i++) cin >> a[i];
    a[n] = 0;
    sort(a.begin(),a.end(),cmp);
    int cnt = 0;
    while (a[1]){
        a[0] -= max(a[1] - a[2],1);
        a[1] -= max(a[1] - a[2],1);
        cnt += max(a[1] - a[2],1);
        sort(a.begin(),a.end(),cmp);
    }
    cout << cnt << '\n';
}