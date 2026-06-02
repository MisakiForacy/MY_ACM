#include <bits/stdc++.h>
using namespace std;
const vector<string> T1 = {"DD","CA","CL"};
struct info{
    string name;
    int att;
    int fav;
};
static inline bool cmp(const info &a, const info &b){
    if(a.att != b.att)return a.att > b.att;
    else if(a.fav != b.fav)return a.fav > b.fav;
    else return a.name > b.name;
}
int main(){
    int n;
    cin >> n;
    string name, type;
    int att,camp;
    int total = 0;
    bool flag = true;
    vector<info>front;
    vector<info>back;
    int f[4];
    cin >> f[0] >> f[1] >> f[2] >> f[3];
    while(n--){
        cin >> name >> att >> type >> camp;
        if(find(T1.begin(),T1.end(),type)!=T1.end()){
            front.push_back({(string)name,(int)att,(int)f[camp-1]});
        }
        else{
            back.push_back({(string)name,(int)att,(int)f[camp-1]});
        }
    }
    if(front.size()<3 || back.size()<3){
        cout << "NO" << endl;
        flag = false;
    }
    if(flag){
        sort(front.begin(),front.end(),cmp);
        sort(back.begin(),back.end(),cmp);
        for(int i=0;i<3;i++)total += front[i].att;
        for(int i=0;i<3;i++)total += back[i].att;
        cout << total << endl;
        for(int i=0;i<3;i++){
            cout << front[i].name << endl;
        }
        for(int i=0;i<3;i++){
            cout << back[i].name << endl;
        }
    }
    return 0;
}