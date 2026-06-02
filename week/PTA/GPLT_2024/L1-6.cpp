#include <bits/stdc++.h>
using namespace std;
struct info{
    double p;
    int s;
};
int main(){
    int n;
    cin >> n;
    vector<info>N(n);
    for(int i=0;i<n;i++)cin >> N[i].p;
    int i,t;
    cin >> i >> t;
    while(!(i==0 && t==0)){
        N[i-1].s+=t;
        cin >> i >> t;
    }
    double s = 0;
    for(i = 0;i<n;i++){
        s += N[i].p * N[i].s;
        cout << N[i].s << endl;
    }
    cout << fixed << setprecision(2) << s << endl;
}