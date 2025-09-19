#include <bits/stdc++.h>
using namespace std;
int n;
struct info{
    int idx,a;
};
int main(){
    cin >> n;
    vector<info>arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i].a;
        arr[i].idx = i;
    }
    sort(arr.begin(),arr.end(),[&](info&a,info&b){if(a.a!=b.a)return a.a<b.a;return a.idx<b.idx;});
    for(int i=1;i<=n;i++){
        cout << arr[i].idx << " ";
    }
}