#include <bits/stdc++.h>
// #define endl '\n'
using namespace std;
struct info{
    string name;
    int f;
    int w;
};
static inline bool cmp(const info &a, const info &b);
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int n,m;
    bool flag = true;
    cin >> n >> m;
    // while(scanf("%d%d",&n,&m) != EOF){ 
    vector<info>fish(n);
    vector<string>eat;
    flag = true;
    for(int i=0;i<n;i++){
        cin >> fish[i].name >> fish[i].f >> fish[i].w;
    }
    sort(fish.begin(),fish.end(),cmp);
    for(int t=0;t<n;t++){
        if(m > 0){
            if(fish[t].f < 10){
                flag = false;
                cout << "sick!" << endl;
                break;
            }
            m -= fish[t].w;
            eat.push_back(fish[t].name);            
        }
        if(m <= 0 ){
            flag = false;
            cout << "enough!" << endl;
            for(vector<string>::iterator it = eat.begin(); it != eat.end(); it++){
                cout << *it << endl;
            }
            break;
        }
    }
    if(flag){
        cout << "go fishing again! " << m << endl;
    }
    // }
    return 0;
}
static inline bool cmp(const info &a,const info &b){
    if(a.f != b.f)return a.f > b.f;
    else if(a.w != b.w)return a.w > b.w;
    else return a.name < b.name;
}