#include <bits/stdc++.h>
using namespace std;
int main(){
    int i,j,count = 0;
    vector<int>a;
    vector<int>b;
    string str;
    getline(cin,str);
    for(i=0;i<str.length();i++){
        if(str[i]=='6'){
            count++;
        }
        else{
            a.push_back(i);
            b.push_back(count);
            count = 0;
        }
    }
    if(count!=0){
        a.push_back(i);
        b.push_back(count);
    }
    for(i=a.size()-1;i>-1;i--){
        if(b[i]>3&&b[i]<=9)str.replace(a[i]-b[i],b[i],"9");
        else if(b[i]>9)str.replace(a[i]-b[i],b[i],"27");
    }
    for(i=0;i<str.length();i++){
        cout << str[i];
    }
    cout << endl;
    return 0;
}