#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N (i64)(1e6+10)
using namespace std;
typedef long long i64;
struct info{
    i64 a,b;
};
vector<info>el,tw;
bool flag = true;
string s;
i64 i,ela,elb,twa,twb;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    ela = elb = twa = twb = 0;
    while(flag){
        cin >> s;
        for(i=0;i<s.length();i++){
            if(s[i]=='W')ela++,twa++;
            else if(s[i]=='L')elb++,twb++;
            if(s[i]=='E'){
                flag = false;
                el.push_back({ela,elb});
                tw.push_back({twa,twb});
            }
            if((ela>=11&(ela-elb)>=2)|(elb>=11&(elb-ela)>=2)|(ela>=11&elb>=11&abs(ela-elb)==2)){
                el.push_back({ela,elb});
                ela = elb = 0;
            }
            if((twa>=21&(twa-twb)>=2)|(twb>=21&(twb-twa)>=2)|(twa>=21&twb>=21&abs(twa-twb)==2)){
                tw.push_back({twa,twb});
                twa = twb = 0;
            }
        }
    }
    for(i = 0; i < el.size(); i++){
        printf("%d:%d\n",el[i].a,el[i].b);
    }
    printf("\n");
    for(i = 0; i < tw.size(); i++){
        printf("%d:%d\n",tw[i].a,tw[i].b);
    }
}