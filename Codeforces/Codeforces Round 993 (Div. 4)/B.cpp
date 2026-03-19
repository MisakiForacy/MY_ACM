#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		string s;
		cin >> s;
		reverse(s.begin(),s.end());
		for (int i=0;i<s.length();i++){
			if (s[i] == 'q'){
				s[i] = 'p';
			} else if (s[i] == 'p'){
				s[i] = 'q';
			}
		}
		cout << s << '\n';
	}
}