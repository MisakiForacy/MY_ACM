#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
struct info{
    i64 k,n;
};
i64 m,i,j;
string n;
vector<info>a;
int main(){
    cin >> m >> n;
    for(i=0;i<n.length();i++){
        if(n[i]!='0')a.push_back({(i64)(n.length()-i-1),(i64)(n[i]-'0')});
    }
    cout << a[0].n << '*' << m << '^' << a[0].k;
    for(i=1;i<a.size();i++){
        cout << '+' << a[i].n << '*' << m << '^' << a[i].k;
    }
}