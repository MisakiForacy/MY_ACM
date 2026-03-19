#include <bits/stdc++.h>
using namespace std;
using LL = long long;
bool check(string s){
    if (s.length() < 6) return 0;
    if (s[1] == '-') return 0;
    int cnt = 0;
    for (int i=s.length()-1;i>=s.length()-3;i--){
        if (s[i] == '-') return 0;
    }
    for (int i=1;i<s.length();i++){
        if (s[i] == '-') return 1;
    }
    return 0;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        s = ' ' + s;
        if (check(s)){
            int n1,n2,ti,id,l,r;
            n1 = n2 = 0;
            for (int i=s.length()-1;i>0;i--){
                if (s[i] == '>') n1 ++;
                else{
                    id = i + 1;
                    break;
                }
            }
            vector<int> a;
            for (int i=1;i<id;i++){
                if (s[i] == '>'){
                    a.push_back(i);
                    n2 ++;
                }
            }
            ti = max(n2,n1/3+(n1%3?1:0));
            cout << "Yes " << ti << '\n';
            l = -1, r = s.length();
            for (int i=0;i<ti;i++){
                l = min(l + 1, (int)a.size()-1);
                r = max(id,r - 3);
                cout << a[l] << ' ' << r - a[l] + 3 << '\n';
            }
        } else{
            cout << "No\n";
        }
    }
}