#include <bits/stdc++.h>
using namespace std;
struct info{
    string s;
    int a,b,c,d;
};
bool cmp(info a,info b){
    // if (a.d!=b.d) return a.d < b.d;
    return a.s < b.s;
}
int main(){
    int n;
    cin >> n;
    vector<info>ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i].s >> ar[i].a >> ar[i].b >> ar[i].c;
        ar[i].d = ar[i].a + ar[i].b + ar[i].c;
    }
    sort(ar.begin(),ar.end(),cmp);
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (abs(ar[i].a-ar[j].a)<=5&&abs(ar[i].b-ar[j].b)<=5&&abs(ar[i].c-ar[j].c)<=5&&abs(ar[i].d-ar[j].d)<=10){
                cout << ar[i].s << ' ' << ar[j].s << '\n';
            }
        }
    }
}