#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,xx,n;
vector<int>ans;
int main(){
    cin >> T;
    while (T --){
        ans.clear();
        cin >> xx;
        while (xx){
            ans.push_back(xx%2);
            xx /= 2;
        }
        ans.push_back(0);
        for (int i=0;i<(ll)(ans.size())-1;i++){
            if (ans[i]&ans[i+1]){
                ans[i] = -1;
                for (int j=i+1;j<(ll)(ans.size());j++){
                    if (ans[j]&ans[i]){
                        ans[j] = 0;
                    } else{
                        ans[j] = 1;
                        break;
                    }
                }
            }
        }
        if (ans[ans.size()-1]){
            n = ans.size();
        } else{
            n = ans.size()-1;
        }
        cout << n << '\n';
        cout << ans[0];
        for (int i=1;i<n;i++){
            cout << " " << ans[i];
        }cout << '\n';
    }
}