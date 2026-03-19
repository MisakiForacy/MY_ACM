#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void toB(vector<int>&ar,ll n){
    while (n){
        ar.push_back(n%2);
        n /= 2;    
    }
}
int main(){
    ll T,x,y,ans,mi,ma;
    vector<int>ax,ay,ac;
    cin >> T;
    while (T --){
        ans = 0;
        cin >> x >> y;
        ax.clear(),ay.clear(),ac.clear();
        toB(ax,x),toB(ay,y);
        mi = min(ax.size(),ay.size());
        ma = max(ax.size(),ay.size());
        for (int i=0;i<mi;i++){
            ac.push_back((ax[i]!=ay[i]));
        }
        for (int i=mi;i<ma;i++){
            if (max(x,y)==x){
                ac.push_back(ax[i]);
            } else{
                ac.push_back(ay[i]);
            }
        }
        for (int i=0;i<ac.size();i++){
            if (ac[i]){
                ans = pow(2,i);
                break;
            }
        }
        cout << ans << '\n';
    }
}