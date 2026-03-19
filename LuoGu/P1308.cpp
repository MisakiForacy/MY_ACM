#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int i;
    int count=0,first_position=-1;
    bool flag = true;
    string s1;
    string s2;
    string ss="";
    vector<string>str;
    cin >> s1;
    getchar();
    getline(cin,s2);
    for(i=0;i<s1.length();i++){
        if('A'<=s1[i]&&s1[i]<='Z'){
            s1[i] = s1[i] + 32;
        }
    }
    for(i=0;i<s2.length();i++){
        if('A'<=s2[i]&&s2[i]<='Z'){
            s2[i] = s2[i] + 32;
        }
    }
    for(i=0;i<s2.length();i++){
        if(s2[i]==' '){
            str.push_back(ss);
            if(ss==s1&&flag)first_position=i-ss.length(),flag=false;
            ss = "";
            continue;
        }
        ss.push_back(s2[i]);
    }
    str.push_back(ss);
    for(i=0;i<str.size();i++){
        if(str[i]==s1){
            count++;
        }
    }
    if(flag)cout << -1;
    else cout << count << " " << first_position;
}