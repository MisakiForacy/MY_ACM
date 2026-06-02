#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n,m,x;
    int maxi = -INF,maxv = -INF;
    map<int,int>dict;
    cin >> n;
    while(n--){
        cin >> m;
        while(m--){
            cin >> x;
            if(dict.find(x)==dict.end()){
                dict.insert(pair<int,int>(x,1));
            }
            else{
                dict[x]++;
            }
        }
    }
    for(map<int,int>::iterator it=dict.begin();it!=dict.end();it++){
        if(it->second>maxi){
            maxi = it->second;
            maxv = it->first;
        }
        else if(it->second==maxi&&it->first>maxv){
                maxv = it->first;
        }
    }
    cout << maxv << " " << maxi;
    return 0;
}