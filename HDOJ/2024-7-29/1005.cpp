#include <bits/stdc++.h>
using namespace std;
const char alp[] = {'A','B','C','D','E'};
void border(int n){
    cout << '+';
    for (int i=0;i<n;i++) cout << '-';
    cout << '+';
    cout << '\n';
}
void line(int m,int hp,int dmg){
    vector<char>s(m);
    cout << '|';
    if (hp>m){
        for (int i=0;i<m;i++){
            s[i] = '.';
        }
        if (dmg < m){
            int u1 = (hp / m + 4) % 5;
            int u2 = (u1 + 1) % 5;
            for (int i=0;i<m;i++){      //绘制一开始的血条
                s[i] = (i<(hp%m)?alp[u2]:alp[u1]);
            }
            if (dmg){
                for (int i=hp%m-1;i>=0;i--){
                    dmg --;
                    s[i] = '.';
                    if (!dmg) break;
                }
            }
            if (dmg){
                for (int i=m-1;i>=0;i--){
                    dmg --;
                    s[i] = '.';
                    if (!dmg) break;
                }
            }
        }
    } else{
        for (int i=0;i<m;i++){
            s[i] = " ."[i<hp];
        }
        for (int i=0;i<hp-dmg;i++) s[i] = 'A';
    }

    for (int i=0;i<m;i++) cout << s[i];
    cout << '|';
    cout << '\n';
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,m,hp,dmg;
        cin >> n >> m >> hp >> dmg;
        border(m);
        for (int i=0;i<n;i++) line(m,hp,dmg);
        border(m);
    }
}