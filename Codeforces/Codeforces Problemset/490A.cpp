#include <bits/stdc++.h>
using namespace std;
struct info{
    int s,i,f;
};
int main(){
    int n,a,b,c;
    cin >> n;
    vector<info>m(n);
    a = 0, b = 0, c = 0;
    for (int i=0;i<n;i++){
        cin >> m[i].s;
        m[i].i = i+1;
        m[i].f = 1;
        if (m[i].s==1){
            a ++;
        } else if (m[i].s==2){
            b ++;
        } else{
            c ++;
        }
    }
    int ans = min(a,min(b,c));
    cout << ans << '\n';
    for (int i=0;i<ans;i++){
        for (int i=0;i<n;i++){
            if (m[i].f&&m[i].s==1){
                cout << m[i].i << " ";
                m[i].f = 0;
                break;
            }
        }
        for (int i=0;i<n;i++){
            if (m[i].f&&m[i].s==2){
                cout << m[i].i << " ";
                m[i].f = 0;
                break;
            }
        }
        for (int i=0;i<n;i++){
            if (m[i].f&&m[i].s==3){
                cout << m[i].i << '\n';
                m[i].f = 0;
                break;
            }
        }
    }

}