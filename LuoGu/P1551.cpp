#include <bits/stdc++.h>
using namespace std;
const int N = 5005;

int Set[N];

int findx(int x){
    if (Set[x] != x){
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}

void merge(int a,int b){
    Set[a] = b;
}

int main(){
    int n,m,q,a,b;
    cin >> n >> m >> q;
    for (int i=0;i<=n;i++) Set[i] = i;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        merge(findx(min(a,b)),findx(max(a,b)));
    }
    for (int i=0;i<q;i++){
        cin >> a >> b;
        if (findx(a)==findx(b)){
            cout << "Yes\n";
        } else{
            cout << "No\n";
        }
    }
}