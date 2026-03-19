#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,flg = 1;
        cin >> n;
        vector<int>ar(n+1),br(n+1);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        for (int i=1;i<=n;i++){
            cin >> br[i];
        }
        map<int,int>m;
        vector<int>cop_ar(ar.begin(),ar.end());
        vector<int>cop_br(br.begin(),br.end());
        sort(cop_ar.begin(),cop_ar.end());
        sort(cop_br.begin(),cop_br.end());
        for (int i=1;i<=n;i++){
            if (cop_ar[i] != cop_br[i]){
                flg = 0;
                break;
            }
        }
        for (int i=1;i<=n;i++){
            int idx = find(br.begin(),br.end(),ar[i]) - br.begin();
            m[abs(idx-i)] ++;
        }
        int t = 0;
        for (int i=1;i<=n;i++){
            if (ar[i]==br[i]) t++;
        }
        
        for (auto k:m){
            if (k.second&1){
                flg = 0;
            }
        }if (t==n) flg = 1;
        cout << (flg?"YES\n":"NO\n");
    }
}