#include <bits/stdc++.h>
using namespace std;
vector<int>ar;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T,n,f,k,ff;
    cin >> T;
    while (T --){
        cin >> n >> f >> k;
        ar.resize(n);
        for (int i=0;i<n;i++){
            cin >> ar[i];
        }
        ff = ar[f-1];
        sort(ar.begin(),ar.end(),cmp);
        if (n == k){
            cout << "YES\n";
        } else if (ar[k-1] == ff && ar[k] == ff){
            cout << "MAYBE\n";
        } else if (ar[k-1] <= ff){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}