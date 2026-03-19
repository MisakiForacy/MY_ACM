#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    bool flag = true;
    int maxn = -INF,minn = INF,datle;
    string str;
    cin >> str;
    vector<int>count(26,0);
    for(int i=0;i<str.length();i++){
        count[str[i]-'a']++;
    }
    for(vector<int>::iterator it=count.begin();it!=count.end();it++){
        if(*it>maxn)maxn = *it;
        if(*it<minn && *it!=0)minn = *it;
    }
    datle = abs(maxn - minn);
    if(datle==0 || datle==1)flag = false;
    for(int i=2;i<int(sqrt(datle));i++){
        if(datle%i==0){
            flag = false;
            break;
        }
    }
    if(flag)cout << "Lucky Word" << endl << datle;
    else cout << "No Answer" << endl << 0;
}