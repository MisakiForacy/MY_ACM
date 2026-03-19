#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin >> n >> t;
    vector<int>ar(n+1),prefix(n+1,0);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        prefix[i] = prefix[i-1] + ar[i];
    }
    int mx = 0;
    for (int i=1;i<=n-mx;i++){
        for (int j=i+mx;j<=n;j++){
            if (prefix[j]-prefix[i-1]<=t){
                mx ++;
            } else{
                break;
            }
        }
    }
    cout << mx << '\n';
}