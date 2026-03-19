#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main(){
    int n;
    int i,sum=0,mins = INF;
    double ave;
    string name,minw;
    int score;
    cin >> n;
    map<string,int>dict;
    for(i=0;i<n;i++){
        cin >> name >> score;
        sum += score;
        dict.insert(pair<string,int>(name,score));
    }
    ave = sum / n / 2;
    for(map<string,int>::iterator it=dict.begin();it!=dict.end();it++){
        if(abs(it->second-ave)<mins){
            mins = abs(it->second-ave);
            minw = it->first;
        }
    }
    cout << ave << " " << minw << endl;
}