#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
int a[10005];
vector<int> p;
void init(){
    a[1] = 1;
    for (int i=2;i<=10000;i++){
        if (!a[i]){
            p.push_back(i);
            for (int j=i*i;j<=10000;j+=i){
                a[j] = 1;
            }
        }
    }
}
int main(){
    int n;
    init();
    while (cin >> n){
        for (int i=n/2;i>=1;i--){
            if (find(all(p),i)!=p.end()&&find(all(p),n-i)!=p.end()){
                cout << i << ' ' << n-i << '\n';
                break;
            }
        }
    }
}