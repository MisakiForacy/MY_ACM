#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,i=0;
    string s;
    cin >> k;
    while(1){
        getline(cin,s);
        if(s=="End")break;
        else{
            if(i%k!=1){
                if(s=="ChuiZi")cout<<"Bu"<<endl;
                else if(s=="JianDao")cout<<"ChuiZi"<<endl;
                else if(s=="Bu")cout<<"JianDao"<<endl;
            }
            else{
                if(s=="ChuiZi")cout<<"ChuiZi"<<endl;
                else if(s=="JianDao")cout<<"JianDao"<<endl;
                else if(s=="Bu")cout<<"Bu"<<endl;
            }
        }
        i++;
    }
    return 0;
}