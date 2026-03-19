#include <bits/stdc++.h>
using namespace std;
int main(){
    int L,N,s;
    cin >> L >> N;
    vector<char>res;
    s = pow(26,L) - N;
    while(s!=0||res.size()!=L){
        res.push_back(s%26+'a');
        s = s/26;
    }
    for(vector<char>::reverse_iterator it=res.rbegin();it!=res.rend();it++)cout<<*it;
    return 0;
}