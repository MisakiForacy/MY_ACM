#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;
typedef double db;
using namespace std;
const struct sss{
    string ss;
    int nn;
}a[26]={"one",1,"two",2,"three",3,"four",4,"five",5,"six",6,"seven",7,"eight",8,"nine",9,"ten",10,
      "eleven",11,"twelve",12,"thirteen",13,"fourteen",14,"fifteen",15,"sixteen",16,"seventeen",17,"eighteen",18,
      "nineteen",19,"twenty",20,"a",1,"both",2,"another",1,"first",1,"second",2,"third",3};
int main(){
    ll res = 0;
    string str;
    getline(cin,str);
    vector<int>num;
    vector<string>words;
    str.erase(str.length()-1);
    for(int i=0;i<str.length();i++){
        if('A'<=str[i]&&str[i]<='Z'){
            str[i] += 32;
        }
    }
    for(int i=str.length()-1;i>-1;i--){
        if(str[i]==' '){
            words.push_back(str.substr(i+1,str.length()-i-1));
            str.erase(i);
            // cout << str << endl;
        }
    }
    words.push_back(str);
    for(vector<string>::iterator it=words.begin();it!=words.end();it++){
        for(int i=0;i<26;i++){
            if(*it==a[i].ss){
                num.push_back(int(pow(a[i].nn,2))%100);
                // cout << int(pow(a[i].nn,2))%100 << endl;
                break;
            }
        }
    }
    sort(num.begin(),num.end());
    for(int i=0;i<num.size();i++){
        res += num[i] * pow(100,num.size()-i-1);
    }
    cout << res;
}
