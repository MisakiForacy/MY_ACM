#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int>ar;
bool isprime(int n){
    if (n==1) return 1;
    for (int i=2;i<=sqrt(n);i++){
        if (!(n%i)) return 0;
    }
    return 1;
}
int dfs(int sum,int idx,int res){
    int ans = 0;
    if (!res){
        return isprime(sum);
    }
    for (int i=idx;i<n;i++){
        ans += dfs(sum+ar[i],i+1,res-1);
    }
    return ans;
}
int main(){
    cin >> n >> k;
    ar.resize(n);
    for (int i=0;i<n;i++){
        cin >> ar[i];
    }
    cout << dfs(0,0,k) << '\n';
}