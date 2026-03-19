#include <bits/stdc++.h>
using namespace std;
struct score{
    int tts,pat,flag = 0;
};
int main(){
    int n,k,s,x1,x2;
    int i,j,total = 0;
    cin >> n >> k >> s;
    map<int,int>mm;
    for(i=0;i<n;i++){
        cin >> x1 >> x2;
        if(x1>=175){
            if(x2>=s)total++;
            else{
                if(mm.find(x1)==mm.end()){
                    mm.insert(pair<int,int>(x1,1));
                }
                else{
                    mm[x1]++;
                }
            }
        }
    }
    cout << total << endl;
    for(map<int,int>::iterator it=mm.begin();it!=mm.end();it++){
        if(it->second>=k){
            total += k;
        }
        else{
            total += it->second;
        }
    }
    cout << total;
    return 0;
}