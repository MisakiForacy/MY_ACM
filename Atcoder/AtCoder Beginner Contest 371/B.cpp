#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    map<int,int> mp;
    int a;
    char b;
    for (int i=0;i<m;i++){
        cin >> a >> b;
        if (b=='M'){
            if (mp[a]==0){
                cout << "Yes\n";
                mp[a] ++;
            } else{
                cout << "No\n";
            }
        } else{
            cout << "No\n";
        }
    }
}