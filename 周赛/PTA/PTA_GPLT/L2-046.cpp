#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef double db;
struct info{
    string school;
    ll num;
};
static inline bool cmp(const info &a,const info &b){
    return a.num>b.num;
}
int main(){
    bool flag;
    ll n,c,sum = 0,tt;
    int i,ii,index;

    string test_str,test_str0;
    int test_t;

    cin >> n >> c;
    vector<info>list(n);
    vector<string>range;
    map<string,int>dict;
    for(i=0;i<n;i++){
        cin >> list[i].school >> list[i].num;
        dict.insert(pair<string,int>(list[i].school,0));
        range.push_back(list[i].school);
        sum = sum + list[i].num;
    }
    tt = (sum%c?sum/c+1:sum/c);
    vector<ll>room(tt,c);
    sort(list.begin(),list.end(),cmp);
    ii = 0;
    index = -1;
    while(list[ii].num){

        test_str0 = list[ii].school;
        test_t = dict[test_str0];



        flag = true;
        if(list[ii].num>=c){
            index++;
            list[ii].num -= c;
            room[index] = 0;
        }
        else if(list[ii].num<c){
            for(i=0;i<=index;i++){
                if(list[ii].num<=room[i]){
                    flag = false;
                    room[i] -= list[ii].num;
                    list[ii].num = 0;
                    break;
                }
            }
            if(flag){
                index++;
                room[index] -= list[ii].num;
            }
        }

        dict[list[ii].school]++;

        sort(list.begin(),list.end(),cmp);
    }
    for(vector<string>::iterator it=range.begin();it!=range.end();it++){
        cout << *it << " " << dict[*it] << endl;
    }
    cout << tt << endl;
    return 0;
}