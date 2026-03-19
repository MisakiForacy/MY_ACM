#include <bits/stdc++.h>
using namespace std;
int t,n,m,k;
struct info{
    char c;
    bool f;
};
vector<info>v(4);
string line;
int main(){
    scanf("%d",&t);
    while(t --){
        k = 0;
        v[0].c='v',v[1].c='i',v[2].c='k',v[3].c='a';
        v[0].f=v[1].f=v[2].f=v[3].f=0;
        scanf("%d%d",&n,&m);
        vector<vector<char>>ma(n,vector<char>(m));
        for(int i=0;i<n;i++){
            cin >> line;
            for(int j=0;j<m;j++){
                ma[i][j] = line[j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(ma[i][j]==v[k].c){
                    v[k].f = 1;
                    k++;
                    break;
                }
            }
        }
        if(v[0].f&v[1].f&v[2].f&v[3].f)cout << "Yes\n";
        else cout << "No\n"; 
    }
    return 0;
}