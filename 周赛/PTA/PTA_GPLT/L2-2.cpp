#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef double db;
using namespace std;
struct user{
    string id;
    int count;
};
int main(){
    int n;
    string id,str;
    cin >> n;
    map<string,int>ID;
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,id);
        getline(cin,str);
        for(int j=0;j<str.length();j++){
            str[j] = tolower(str[j]);
        }
        while(str.find("chatgpt")!=-1){
            str.erase(str.find("chatgpt"),7);
            ID[id]++;
        }
    }
    int maxn = -INF;
    for(int j=0;j<3;j++){
        maxn = -INF;
        for(auto i:ID){
            if(i.second > maxn){
                id = i.first;
                maxn = i.second;
            }
        }
        if(maxn<=0)break;
        cout << id << " " << ID[id] << endl;
        ID[id] = -1;
    }
}