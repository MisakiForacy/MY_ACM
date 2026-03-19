#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int s1[N],s2[N];
void init(int n,int *s){
    for (int i=0;i<=n;i++){
        s[i] = i;
    }
}
int findx(int x,int *s){
    if (s[x] != x){
        s[x] = findx(s[x],s);
    }
    return s[x];
}
void merge(int a,int b,int *s){
    s[max(a,b)] = s[min(a,b)];
}
int main(){
    int n,m,p,q,x,y;
    cin >> n >> m >> p >> q;
    init(n,s1);
    init(m,s2);
    for (int i=0;i<p;i++){
        cin >> x >> y;
        merge(findx(x,s1),findx(y,s1),s1);
    }
    for (int i=0;i<q;i++){
        cin >> x >> y;
        merge(findx(abs(x),s2),findx(abs(y),s2),s2);
    }
    int cnt1,cnt2;
    cnt1 = cnt2 = 0;
    for (int i=1;i<=n;i++){
        if (s1[i]==1) cnt1 ++;
    }
    for (int i=1;i<=m;i++){
        if (s2[i]==1) cnt2 ++;
    }
    cout << min(cnt1,cnt2) << '\n';
}