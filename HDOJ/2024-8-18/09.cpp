#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
const int P = 131;
const int N = 1e6+5;

ll h1[N],p1[N],h2[N],p2[N];

void readline(string &_str,char _end = '\n'){ // 字符串快速读入
    _str.clear();
    char _ch = getchar();
    while(!(_ch==_end||_ch=='\n')){_str.push_back(_ch);_ch=getchar();}
}

ll get1(int l, int r)
{
    return (h1[r] - h1[l-1] * p1[r-l+1]);
}

ll get2(int l,int r){
    return (h2[r] - h2[l-1] * p2[r-l+1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        string a,b;
        readline(a,' ');
        readline(b);
        int la = a.length();
        int lb = b.length();
        a = ' ' + a;
        b = ' ' + b;
        for (int i=1;i<=max(la,lb)+1;i++){
            p1[i] = p2[i] = h1[i] = h2[i] = 0;
        }
        if (la > lb){
            swap(la,lb);
            swap(a,b);
        }
        p1[0] = p2[0] = 1;
        for (int i=1;i<=la;i++){
            h1[i] = (h1[i-1] * P + a[i]) % mod;
            p1[i] = p1[i-1] * P % mod;
        }
        for (int i=1;i<=lb;i++){
            h2[i] = (h2[i-1] * P + b[i]) % mod;
            p2[i] = p2[i-1] * P % mod;
        }
        int cnt = 0;
        if (la*2 <= lb){
            for (int i=1;i+la-1<=lb;i++){
                if (get1(1,la)==get2(i,i+la-1)){
                    cnt ++;
                    i += la-1;
                }
            }
        }
        if (cnt>1){
            cout << -1 << '\n';
        } else{
            int l1,l2;
            l1 = l2 = 0;
            char ed = a.back();
            for (int i=la;i>=1;i--){
                if (b[i]==ed && get1(la-i+1,la)==get2(1,i)){
                    l1 = i;
                    break;
                }
            }
            char st = a[1];
            for (int i=lb-la+1;i<=lb;i++){
                if (b[i]==st && get1(1,lb-i+1)==get2(i,lb)){
                    l2 = lb - i + 1;
                    break;
                }
            }
            a.erase(0,1), b.erase(0,1);
            if (b.find(a)!=-1){
                l1 = la;
            }
            cout << la + lb - max(l1,l2) << '\n';
        }
    }
}