#include <bits/stdc++.h>
using namespace std;
struct info{
    string s;
    int m,p;
};
bool cmp(info a,info b){
    if (a.p!=b.p) return a.p < b.p;
    return a.m > b.m;
}
int main(){
    int n;
    int sum,cnt;
    cin >> n;
    sum = cnt = 0;
    vector<info>ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i].s >> ar[i].m >> ar[i].p;
        if (!ar[i].p){
            sum += ar[i].m;
            cnt ++;
        }
    }
    double ave = 1.0 * sum / cnt;
    sort(ar.begin(),ar.end(),cmp);
    printf("%.1lf\n",ave);
    for (int i=0;i<cnt;i++){
        cout << ar[i].s << '\n';
    }
}