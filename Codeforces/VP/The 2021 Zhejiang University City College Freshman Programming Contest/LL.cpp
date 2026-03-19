#include<bits/stdc++.h>
using namespace std;
int n,m,tap;
string s;
int main()
{
        cin>>n>>m>>s;
        tap = s.size()-1;
        while(s[tap] == 'a') tap--;
        if(tap < 0){
                for(int i=0;i<n-1;i++) cout<<'a';
                return 0;
        }
        cout<<s.substr(0,tap)<<char(s[tap]-1);
        for(int i=tap+1;i<m;i++) cout<<'z';
        return 0;
}