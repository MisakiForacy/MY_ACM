// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,t;
bool found;
string str;
string abstract;
map<string,vector<string>>a;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        abstract = "";
        getline(cin,str);
        if(isalpha(str[0]))abstract.push_back(str[0]);
        for(int j=1;j<str.length();j++){
            if(str[j-1]==' ' && isalpha(str[j])){
                abstract.push_back(str[j]);
            }
        }
        a[abstract].push_back(str);
    }
    for(auto s:a){
        sort(a[s.first].begin(),a[s.first].end());
    }
    scanf("%d",&m);
    getchar();
    for(int i=0;i<m;i++){
        found = false;
        abstract = "";
        getline(cin,str);
        if(isalpha(str[0]))abstract.push_back(str[0]);
        for(int j=1;j<str.length();j++){
            if(str[j-1]==' ' && isalpha(str[j])){
                abstract.push_back(str[j]);
            }
        }
        t = 0;
        if(a[abstract].size()){
            for(vector<string>::iterator it=a[abstract].begin();it!=a[abstract].end();it++){
                if(t)cout << '|' << *it;
                else cout << *it;
                t++;
            }
        }
        else{
            cout << str;
        }
        cout << endl;
    }
    return 0;
}