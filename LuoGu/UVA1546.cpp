#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<ll>a,ll len){
    for (int i=2;i<=len;i++){
        if (a[i]!=a[1]){
            return 0;
        }
    }
    return 1;
}
int main(){
    ll T,s,c;
    cin >> T;
    while (T--){
        ll st;
        cin >> s >> c;
        vector<vector<ll>>diff(105,vector<ll>(s+c+1,0));
        for (int i=1;i<=s;i++){
            cin >> diff[0][i];
        }
        for (int t=1;t<=100;t++){
            for(int j=1;j<=s-t;j++){
				diff[t][j]=diff[t-1][j+1]-diff[t-1][j];
			}
            if (check(diff[t],s-t)){
                st = t;
                break;
            }
        }
        for(int i=s-st+1;i<=s-st+c;i++){
			diff[st][i]=diff[st][i-1];
		}
        for(int i=st-1;i>=0;i--){
			for(int j=s-i+1;j<=s+c;j++){
				diff[i][j]=diff[i+1][j-1]+diff[i][j-1];
			}
		}
        for(int i=s+1;i<=s+c;i++){
			cout << diff[0][i] << " \n"[i==s+c];
		}
    }
}