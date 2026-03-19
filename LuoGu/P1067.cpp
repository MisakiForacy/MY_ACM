#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n;
    string s = "";
    for (int i=0;i<=n;i++){
        cin >> x;
        if (x && n-i){
            if (x==1){
                s.append("+x");
            } else if (x==-1){
                s.append("-x");
            } else if (x>1){
                s.append('+'+to_string(x)+'x');
            } else if (x<-1){
                s.append('-'+to_string(-x)+'x');
            }
            if (n-i>1){
                s.append('^'+to_string(n-i));
            }
        } else if (!(n-i) && x){
            if (x < 0) s.append(to_string(x));
            else s.append('+'+to_string(x));
        }
    }
    if (s[0]=='+') s.erase(0,1);
    cout << s << '\n';
}