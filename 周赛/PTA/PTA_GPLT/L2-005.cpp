#include <bits/stdc++.h>
#define N 100000
typedef long long ll;
using namespace std;
void print(vector<int>arr){
    int i;
    for(i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int i,j;
    int n,m,k,x;
    int a,b;
    int nc,nt;
    vector<ll>num(N,0);
    cin >> n;
    vector<vector<int>>arr(n);
    for(i=0;i<n;i++){
        cin >> m;
        vector<ll>num(N,0);
        for(j=0;j<m;j++){
            cin >> x;
            if(x>N){
                x = x % (N-1);
            }
            if(!num[x]){
                arr[i].push_back(x);
                num[x] = 1;
            }
        }
    }
    cin >> k;
    for(i=0;i<k;i++){
        nc = 0,nt = 0;
        vector<ll>num(N,0);
        cin >> a >> b;
        a--,b--;
        for(j=0;j<arr[a].size();j++){
            if(!num[arr[a][j]]){
                num[arr[a][j]] = 1;
                nt++;
            }
        }
        for(j=0;j<arr[b].size();j++){
            if(!num[arr[b][j]]){
                num[arr[b][j]] = 1;
                nt++;
            }
            else{
                nc++;
            }
        }
        cout << fixed << setprecision(2) << 1.0*nc/nt*100 << "%" << endl;
    }
}