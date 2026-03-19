#include <bits/stdc++.h>
using namespace std;
struct haha{
    int be,ed;
};
bool cmp(haha a,haha b){
    return a.ed < b.ed;
}
int main(){
    int n;
    cin >> n;
    vector<haha>a(n);
    for (int i=0;i<n;i++){
        cin >> a[i].be >> a[i].ed;
    }
    sort(a.begin(),a.end(),cmp);
    vector<int>ans(1,0);
    for (auto x:a){
        if (x.be >= ans.back()){
            ans.push_back(x.ed);
        }
    }
    cout << ans.size()-1 << '\n';
}