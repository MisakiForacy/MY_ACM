#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long i64;
string s,s0,s1;
i64 t,n,i,j,k,cnt1,cnt2;
bool flg;
vector<i64>arr;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        arr.clear();
        cin >> n >> s;
        for(i=1;i<=n;i++){
            if(!(n%i))arr.push_back(i);
        }
        for(auto &i:arr){
            s0 = "", s1 = "";
            cnt1 = 0, cnt2 = 0;
            for(j=0;j<i;j++)s0.push_back(s[j]);
            if(i*2<=n)for(j=i;j<i*2;j++)s1.push_back(s[j]);
            else for(j=0;j<i;j++)s1.push_back(s[j]);
            for(j=0;j<n;j+=i){
                for(k=0;k<i;k++){
                    if(s0[k] != s[j+k])cnt1++;
                    if(s1[k] != s[j+k])cnt2++;
                }
            }
            if(min(cnt1,cnt2)<2){
                cout << i << endl;
                break;
            }
        }
    }
}