#include <bits/stdc++.h>
using namespace std;
struct info{
    int s,a,b;
};
int main(){
    int n;
    cin >> n;
    vector<info>l(n);
    for(int i=0;i<n;i++){
        cin >> l[i].s >> l[i].a >> l[i].b;
    }
    for(int i=0;i<n;i++){
        if(l[i].a+l[i].b<=140 || l[i].a * 7 + l[i].b * 3 < 800)cout << "Not excellent" << endl;
        else cout << "Excellent" << endl;
    }
    return 0;
}