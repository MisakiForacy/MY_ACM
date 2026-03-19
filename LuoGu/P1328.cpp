#include <bits/stdc++.h>
using namespace std;
const int res[5][5] = {{0,-1,1,1,-1},
                       {1,0,-1,1,-1},
                       {-1,1,0,-1,1},
                       {-1,-1,1,0,1},
                       {1,1,-1,-1,0}};
int main(){
    int n,na,nb,a,b,k1,k2;
    a = b = k1 = k2 = 0;
    cin >> n >> na >> nb;
    vector<int>ga(na),gb(nb);
    for (int i=0;i<na;i++) cin >> ga[i];
    for (int i=0;i<nb;i++) cin >> gb[i];
    for (int i=0;i<n;i++){
        if (res[ga[k1]][gb[k2]]==1){
            a ++;
        } else if (res[ga[k1]][gb[k2]]==-1){
            b ++;
        }
        k1 = ++k1 % na;
        k2 = ++k2 % nb;
    }
    cout << a << ' ' << b << '\n';
}