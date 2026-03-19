#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<string>a,b;
    string s,web;
    a.push("http://www.acm.org/");
    while (cin >> s){
        if (s=="VISIT"){
            cin >> web;
            a.push(web);
            while (!b.empty()){
                b.pop();
            }
            cout << a.top() << '\n';
        } else if (s=="BACK"){
            b.push(a.top());
            a.pop();
            if (a.empty()){
                a.push(b.top());
                b.pop();
                cout << "Ignored\n";
            } else{
                cout << a.top() << '\n';
            }
        } else if (s=="FORWARD"){
            if (b.empty()){
                cout << "Ignored\n";
            } else{
                a.push(b.top());
                b.pop();
                cout << a.top() << '\n';
            }
        } else if (s=="QUIT"){
            break;
        }
    }
}