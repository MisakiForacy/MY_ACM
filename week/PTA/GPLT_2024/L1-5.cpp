#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n;
    vector<string>forbit(n);
    for(int i=0;i<n;i++)cin >> forbit[i];
    cin >> k;
    int kk = 0;
    getchar();
    string str;
    getline(cin,str);
    for(int i=0;i<n;i++){
        while(str.find(forbit[i])!=-1){
            kk++;
            int index = str.find(forbit[i]);
            string newstr = "";
            for(int j = 0;j < index;j++)newstr.push_back(str[j]);
            newstr.append("-");
            for(int j = index + forbit[i].length();j<str.length();j++)newstr.push_back(str[j]);
            str = newstr;
        }
    }
    if(kk>=k){
        cout << kk << endl;
        cout << "He Xie Ni Quan Jia!" << endl;
    }
    else{
        while(str.find("-")!=-1){
            string newstr = "";
            int index = str.find("-");
            for(int j = 0;j < index;j++)newstr.push_back(str[j]);
            newstr.append("<censored>");
            for(int j = index + 1;j<str.length();j++)newstr.push_back(str[j]);
            str = newstr;
        }
        cout << str << endl;
    }
    return 0;
}