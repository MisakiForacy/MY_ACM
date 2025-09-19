#include <bits/stdc++.h>
using namespace std;
int n,x,y;
struct info{
    int len,x,y,target;
};
vector<vector<int>>m;
vector<int>len;
vector<info>ans;
bool check(int len,int col,int target);
int main(){
    cin >> n >> x >> y;
    m.resize(n+1,vector<int>(n+1,1));
    m[y][x] = 0;
    len.push_back(1);
    for(int i=2;i<n;i++){
        len.push_back(i);
        len.push_back(i);
    }
    len.push_back(n);
    for(int t=0;t<(n-1)*2;t++){
        if(x>n-x){
            for(int i=1;i<=n;i++){

            }
        }
    }
}
bool check(int len,int col,int target){
    if(target){
        for(int )
    }
}