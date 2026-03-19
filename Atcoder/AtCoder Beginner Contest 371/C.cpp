#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
const int N = 10;
const int inf = 0x3f3f3f3f;
vector<int> G[N];
vector<int> H[N];
int A[N][N];
int main(){
    int n;
    int mg,mh;
    cin >> n;
    cin >> mg;
    int u,v,a,b;
    for (int i=0;i<mg;i++){
        cin >> u >> v;
        u --, v --;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> mh;
    for (int i=0;i<mh;i++){
        cin >> a >> b;
        a --, b --;
        H[a].push_back(b);
        H[b].push_back(a);
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            cin >> A[i][j];
        }
    }
    vector<int> ng(n), nh(n);
    iota(all(ng),0);
    iota(all(nh),0);
    int mi = inf;
    do{
        int sum = 0;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if (find(all(G[i]),j)!=G[i].end() && find(all(H(nh[i])),nh[j])==H[nh[i]].end()){
                    sum += A[min(nh[i],nh[j])][max(nh[i],nh[j])];
                }
                if (find(all(G[i]),j)==G[i].end() && find(all(H[nh[i]]),nh[j])!=H[nh[i]].end()){
                    sum += A[min(nh[i],nh[j])][max(nh[i],nh[j])];
                }
            }
        }
        mi = min(mi,sum);
    } while (next_permutation(all(nh)));
    cout << mi << '\n';
}