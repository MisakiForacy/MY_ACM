#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const char ch[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
ll qpow(ll a,ll k){
	ll ans = 1;
	while (k){
		if (k&1) ans = ans * a % mod;
		a = a * a % mod;
		k >>= 1;
	}
	return ans;
}
int get(char c){
	for (int i=0;i<37;i++){
		if (ch[i] == c){
			return i;
		}
	}
}
ll sw(int n,string x){
    ll ans = 0;
	ll len = x.length();
	for (int i=0;i<len;i++){
		ans += qpow(n,len-i-1) * get(x[i]);
	}
    return ans;
}
int main(){
    int n;
	string x;
    cin >> n >> x;
    cout << sw(n,x) << '\n';
}