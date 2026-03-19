#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int Set[N];
void init(int n){
    for (int i=0;i<=n;i++){
        Set[i] = i;
    }
}
int findx(int x){
    if (Set[x] != x){
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void merge(int a,int b){
    a = findx(a);
    b = findx(b);
    
}
int main(){
    int T;
    cin >> T;
    init(30000);
    while (T--){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if (c=='M'){
            merge(findx(x),findx(y));
        } else{
            if (findx(x)!=findx(y)){
                cout << -1 << '\n';
            } else{
                cout << max(x,y)-min(x,y)-1 << '\n';
            }
        }
    }
}