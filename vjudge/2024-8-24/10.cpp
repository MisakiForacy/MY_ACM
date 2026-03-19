#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
const int inf = 0x3f3f3f3f;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int cnt = 0;
    if (is_sorted(a.begin(),a.end())){
        cout << n << '\n';
    } else{
        for (int i=0;i<n;i++){
            if (a[i]!=inf){
                int ls = a[i];
                a[i] = inf;
                for (int j=i+1;j<n;j++){
                    if (a[j]<ls){
                        ls = a[j];
                        a[j] = inf;
                    }
                }
                cnt ++;
            }
        }
        cout << cnt << '\n';
    }
}