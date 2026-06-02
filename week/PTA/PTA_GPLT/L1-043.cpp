#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,hh,mm;
    int name,total = 0,sum = 0;
    char c,comm;
    double ave;
    vector<int>T;
    map<int,int>dict;
    cin >> N;
    while(N){
        cin >> name >> comm >> hh >> c >> mm;
        if(name!=0){
            if((dict.find(name)==dict.end())&&comm=='S'){
                dict.insert(pair<int,int>(name,hh*60+mm));
            }
            else if(dict.find(name)!=dict.end()&&comm=='S'&&dict[name]==-1){
                dict[name] = hh*60+mm;
            }
            else if(dict.find(name)!=dict.end()&&comm=='E'&&dict[name]!=-1){
                T.push_back(hh*60+mm-dict[name]);
                total++;
                dict[name] = -1;
            }
        }
        else{
            N--;
            sum = 0;
            for(vector<int>::iterator it=T.begin();it!=T.end();it++){
                sum += *it;
            }
            if(total!=0)ave = (double)sum/total;
            else ave = 0;
            cout << fixed << setprecision(0) << total << " " << ave << endl;
            total = 0;
            ave = 0;
            T.clear();
            dict.clear();
        }
    }
}