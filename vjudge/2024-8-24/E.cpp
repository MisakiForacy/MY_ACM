#include <bits/stdc++.h>
using namespace std;
struct haha{
    int gd,k;
    string name;
};
int main(){
    int n;
    cin >> n;
    vector<haha> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].gd >> a[i].name;
        a[i].k = 0;
    }
    for (int i=0;i<n;i++){
        if (a[i].k) continue;
        a[i].k = 1;
        for (int j=n-1;j>i;j--){
            if (a[j].k) continue;
            if (a[j].gd != a[i].gd){
                cout << a[i].name << ' ' << a[j].name << '\n';
                a[j].k = 1;
                break;
            }
        }
    }
}