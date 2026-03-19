#include <bits/stdc++.h>
using namespace std;
struct info{
    int id;
    double sum;
    int get;
};
static inline bool cmp(info &a,info &b);
int main(){
    int n,id,t;
    double m;
    cin >> n;
    vector<info>ID(n);
    for(int i=0;i<n;i++){
        cin >> t;
        ID[i].id = i+1;
        for(int j=0;j<t;j++){
            cin >> id >> m;
            m = m/100;
            ID[id-1].sum += m;
            ID[id-1].get++;
            ID[i].sum -= m;
        }
    }
    sort(ID.begin(),ID.end(),cmp);
    for(int i=0;i<n;i++){
        cout << ID[i].id << " " << fixed << setprecision(2) << ID[i].sum << endl;
    }
    return 0;
}
static inline bool cmp(info &a,info &b){
    if(abs(a.sum-b.sum)<0.01 && a.get==b.get){
        return a.id < b.id;
    }
    if(a.sum!=b.sum){
        return a.sum > b.sum;
    }
    else if(a.get!=b.get){
        return a.get > b.get;
    }
}