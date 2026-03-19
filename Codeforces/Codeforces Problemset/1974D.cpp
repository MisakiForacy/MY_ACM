#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,x,y,nn,ss,ww,ee;
        cin >> n;
        x = y = 0;
        string s;
        cin >> s;
        nn = ss = ww = ee = 0;
        for (int i=0;i<n;i++){
            if (s[i]=='N') y ++,nn ++;
            else if (s[i]=='S') y --, ss ++;
            else if (s[i]=='W') x --, ww ++;
            else x ++, ee ++;
        }
        if (n==2 && s[0]!=s[1]){
            cout << "NO\n";
        } else if (abs(x)&1 || abs(y)&1){
            cout << "NO\n";
        } else{
            vector<char>ans(n,'R');
            int yy = y/2;
            int xx = x/2;
            for (int i=0;i<n;i++){
                if (yy>0 && s[i]=='N'){
                    yy --;
                    ans[i] = 'H';
                } else if (yy<0 && s[i]=='S'){
                    yy ++;
                    ans[i] = 'H';
                } else if (xx>0 && s[i]=='E'){
                    xx --;
                    ans[i] = 'H';
                } else if (xx<0 && s[i]=='W'){
                    xx ++;
                    ans[i] = 'H';
                }
            }
            int flg = find(ans.begin(),ans.end(),'H') == ans.end();
            if (flg){
                int f1 = 1, f2 = 1;
                if (xx==0 && ee){
                    for (int i=0;i<n;i++){
                        if (f1 && s[i]=='E'){
                            f1 = 0;
                            ans[i] = 'H';
                        }
                        if (f2 && s[i]=='W'){
                            f2 = 0;
                            ans[i] = 'H';
                        }
                    }
                } else{
                    for (int i=0;i<n;i++){
                        if (f1 && s[i]=='N'){
                            f1 = 0;
                            ans[i] = 'H';
                        }
                        if (f2 && s[i]=='S'){
                            f2 = 0;
                            ans[i] = 'H';
                        }
                    }
                }
            }
            for (int i=0;i<n;i++){
                cout << ans[i];
            }
            cout << '\n';
        }
    }
}