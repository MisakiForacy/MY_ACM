#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
struct info{
    i64 a,b;
};
i64 n,t,h,i,j,a,b;
map<i64,i64>Linked;
vector<i64>arr;
int main(){
    cin >> n >> t;
    cin >> a >> b;
    Linked[a] = b;
    arr.push_back(a);
    for(i=1;i<n-1;i++){
        cin >> a >> b;
        Linked[a] = b;
    }
    cin >> h;
    for(auto &s:Linked){
        arr.push_back(Linked[s.first]);
    }
    for(i=0;i<n;i++){
        if(arr[i] == h)break;
    }
    if((n-i+1)%2 || i%2){
        cout << "Ron";
    }
    else cout << "Hermione";
}