#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,op,score;
    string name;
    cin >> n;
    map<string,int>mp;
    set<string>st;
    for (int i=0;i<n;i++){
        cin >> op;
        if (op == 1){
            cin >> name >> score;
            mp[name] = score;
            st.insert(name);
            cout << "OK\n";
        } else if (op == 2){
            cin >> name;
            if (!mp[name]){
                cout << "Not found\n";
            } else{
                cout << mp[name] << '\n';
            }
        } else if (op == 3){
            cin >> name;
            if (!mp[name]){
                cout << "Not found\n";
            } else{
                mp[name] = 0;
                st.erase(name);
                cout << "Deleted successfully\n";
            }
        } else{
            cout << st.size() << '\n';
        }
    }
}