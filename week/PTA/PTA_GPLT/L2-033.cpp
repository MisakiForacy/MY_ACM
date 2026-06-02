#include <bits/stdc++.h>
using namespace std;
int main(){
    bool flag = true;
    int n,x;
    char s;
    cin >> n;
    stack<int>Num;
    stack<char>Op;
    for(int i=0;i<n;i++){
        cin >> x;
        Num.push(x);
    }
    for(int i=0;i<n-1;i++){
        cin >> s;
        Op.push(s);
    }
    while(Num.size()!=1){
        int n1,n2,n3;
        char op;
        n1 = Num.top();
        Num.pop();
        n2 = Num.top();
        Num.pop();
        op = Op.top();
        Op.pop();
        if(n1==0 && op=='/'){
            cout << "ERROR: " << n2 << "/0" << endl;
            flag = false;
            break;
        }
        if(op=='+')n3 = n2 + n1;
        else if(op=='-')n3 = n2 - n1;
        else if(op=='*')n3 = n2 * n1;
        else if(op=='/')n3 = n2 / n1;
        Num.push(n3);
    }
    if(flag)cout << Num.top() << endl;
}