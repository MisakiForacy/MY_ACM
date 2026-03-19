#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
    int i;
    string str,str1,str2;
    cin >> str1;
    getchar();
    getline(cin,str2);
    // for(i=0;i<str.length();i++){
    //     if(str[i]!=' ')str1.push_back(str[i]);
    //     else break;
    // }
    // for(++i;i<str.length();i++){
    //     if(str[i]!=' ')str2.push_back(str[i]);
    //     else break;
    // }
    for(i=0;i<str1.size();i++){
        if(!('0'<=str1[i]&&str1[i]<='9')){
            str1 = "?";
            break;
        }
    }
    if(str1!="?"){
        if(stoi(str1)<=0 || stoi(str1)>1000)str1="?";
    }
    for(i=0;i<str2.size();i++){
        if(!('0'<=str2[i]&&str2[i]<='9')){
            str2 = "?";
            break;
        }
    }
    if(str2!="?"){
        if(stoi(str2)<=0 || stoi(str2)>1000)str1="?";
    }
    if(str1!="?"&&str2!="?")cout << stoi(str1) << " + " << stoi(str2) << " = " << stoi(str1)+stoi(str2);
    else if(str1!="?") cout << stoi(str1) << " + " << str2 << " = " << "?";
    else if(str2!="?") cout << str1 << " + " << stoi(str2) << " = " << "?";
    else cout << str1 << " + " << str2 << " = " << "?";
}