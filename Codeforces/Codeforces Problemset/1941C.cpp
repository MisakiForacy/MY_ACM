#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,T,cnt;
char s[N];
int main() {
    cin >> T;
    while (T --){
        cin >> n;
        cnt = 0;
        for (int i=0;i<=n;i++) {
            s[i] = getchar();
            if (i>=4&&s[i-4]=='m'&&s[i-3]=='a'&&s[i-2]=='p'&&s[i-1]=='i'&&s[i]=='e') {
                continue;
            } else if (i>=2&&s[i-2]=='p'&&s[i-1]=='i'&&s[i]=='e') {
                cnt ++;
            } else if (i>=2&&s[i-2]=='m'&&s[i-1]=='a'&&s[i]=='p') {
                cnt ++;
            }
        }getchar();
        cout << cnt << '\n';
    }
}