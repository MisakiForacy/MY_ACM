#include <bits/stdc++.h>
using namespace std;
const int D[] = {31,29,31,30,31,30,31,31,30,31,30,31};
bool check(int n1,int n2,int n3,int n4){
    int mm = n1 * 10 + n2;
    int dd = n3 * 10 + n4;
    if (12<mm||mm<1||dd==0) return 0;
    if (D[mm-1]>=dd) return 1;
    else return 0;
}

vector<string> date;
void calc(){
    string val = "";
	for(int i = 0;i<=9;i++){
	for(int j = 0;j<=9;j++){
	for(int k = 0;k<=9;k++){
	for(int l = 0;l<=9;l++){
		if(check(i,j,k,l)){
			val.append(to_string(i));
            val.append(to_string(j));
            val.append(to_string(k));
            val.append(to_string(l));
			date.push_back(val);
            val = "";
		}
	}}}}
}

void build(vector<int>&suf,string s){
    int ok = 1, p1, p2;
    for (int i=0;i<date.size();i++){
        ok = 1,p2 = s.length()-1;
        for (p1=3;p1>=0;p1--){
            while (p2>=0 && s[p2]!=date[i][p1]) p2 --;
            if (p2==-1){
                ok = 0;
                break;
            }
            p2 --;
        }
        if (ok){
            suf[p2] ++;
        }
    }
    for (int i=suf.size()-2;i>=0;i--){
        suf[i] = suf[i] + suf[i+1];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    calc();
    while (T--){
        int n,m,ans = 0;
        cin >> n >> m;
        string s,t;
        cin >> s;
        vector<int>suf(m,0);
        build(suf,s);
        for (int i=0;i<n;i++){
            cin >> t;
            int p1=0,p2=0,ok = 1;
            for (p1=0;p1<int(t.length());p1++){
                while (p2<m&&t[p1]!=s[p2]) p2 ++;
                if (p2==m){
                    ok = 0;
                    break;
                }
                p2 ++;
            }
            if (ok){
                int cnt = 0;
                cnt = suf[p2];
                ans += cnt;
            }
        }
        cout << ans << '\n';
    }
}