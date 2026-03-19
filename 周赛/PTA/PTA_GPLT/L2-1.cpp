#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n;
    int i,j,k;
    cin >> n;
    vector<int>list(n);
    for(i=0;i<n;i++)cin >> list[i];
    vector<int>a;
    vector<int>b;
    vector<int>maxn;
    int len,maxnn = -INF;
    int c;
    i = 0;
    len = 0;
    for(i=0;i<n;i++){
        c = list[i];
        if(!a.size()){
            a.push_back(c);
        }
        else if(c < a[a.size()-1]){
            a.push_back(c);
        }
        else if(!b.size()){
            b.push_back(c);
        }
        else if(c > b[b.size()-1]){
            b.push_back(c);
        }
        else{
            maxn.push_back(a.size());
            a.clear();
            for(j=b.size()-1;j>-1;j--){
                if(b[j]>c){
                    a.push_back(b[j]);
                    b.pop_back();
                }
                else break;
            }
            a.push_back(c);
        }
        // for(k=0;k<b.size();k++)cout << b[k] << " ";cout << endl;
    }
    if(a.size()){
        maxn.push_back(a.size());
    }
    if(b.size()){
        maxn.push_back(b.size());
    }
    for(i=0;i<maxn.size();i++){
        if(maxn[i]>maxnn)maxnn = maxn[i];
    }
    cout << maxn.size() << " " << maxnn << endl;
}