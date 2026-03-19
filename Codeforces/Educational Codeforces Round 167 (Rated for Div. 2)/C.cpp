#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,a,b;
        cin >> n;
        a = b = 0;
        vector<int>ar(n+1);
        vector<int>br(n+1);
        int sub,add;
        sub = add = 0;
        for (int i=1;i<=n;i++) cin >> ar[i];
        for (int i=1;i<=n;i++) cin >> br[i];
        for (int i=1;i<=n;i++){
            if (ar[i]==1&&br[i]<1){
                a ++;
            } else if (br[i]==1&&ar[i]<1){
                b ++;
            } else if ((ar[i]<=0&&br[i]==0)||(ar[i]==0&&br[i]<=0)){
                continue;
            } else if (ar[i]==1&&br[i]==1){
                add ++;
            } else if (ar[i]==-1&&br[i]==-1){
                sub ++;
            }
        }
        if (sub){
            if (abs(a-b)<=sub){
                int nn = a + b - sub;
                a = nn / 2;
                b = nn - a;
            } else if (max(a,b)==a){
                a -= sub;
            } else{
                b -= sub;
            }
        }
        if (add){
            if (abs(a-b)<=add){
                int nn = a + b + add;
                a = nn / 2;
                b = nn - a;
            } else if (max(a,b)==a){
                b += add;
            } else {
                a += add;
            }
        }
        cout << min(a,b) << '\n';
    }
}