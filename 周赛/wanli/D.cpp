#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t,n,score;
    string name,res = "NOTHING";
    bool flag;
    map<string,int>info;
    scanf("%d",&t);
    flag = true;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            cin >> name >> score;
            info[name]+=score;
            if(flag && info[name]>=2000){
                flag = false;
                res = name;
            }
        }
    }
    cout << res << '\n';
    return 0;
}