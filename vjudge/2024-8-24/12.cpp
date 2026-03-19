#include <bits/stdc++.h>
using namespace std;
struct haha{
    string id,f,fa,ma;
};
bool bfs()
int main(){
    int n;
    cin >> n;
    map<string,haha> mp;
    string id,f,fa,ma;
    for (int i=0;i<n;i++){
        cin >> id >> f >> fa >> ma;
        mp[id] = {id,f,fa,ma};
    }
    int k;
    string a,b;
    cin >> k;
    for (int i=0;i<k;i++){
        cin >> a >> b;
        if (mp[a].f==mp[b].f){
            cout << "Never Mind\n";
        }
    }
}