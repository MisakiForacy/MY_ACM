#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);
		set<int> st;
		for (int i=1;i<=n;i++){
			st.insert(i);
		}
		for (int i=0;i<n;i++) cin >> a[i];
		for (int i=0;i<n;i++){
			if (st.count(a[i])){
				b[i] = a[i];
				st.erase(a[i]);
			} else{
				b[i] = *st.begin();
				st.erase(b[i]);				
			}
		}
		for (int i=0;i<n;i++){
			cout << b[i] << " \n"[i==n-1];
		}
	}
}