#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        swap(a[i].first,a[i].second);
    }
    cout << (is_sorted(a.begin(),a.end())?"Poor Alex\n":"Happy Alex\n");
}