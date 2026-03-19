#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,A,B;
    int i=0;
    while(1){
        cin >> s;
        if(s==".")break;
        else{
            i++;
            if(i==2)A=s;
            if(i==14)B=s;
        }
    }
    if(i>=14){
        cout << A << " and " << B << " are inviting you to dinner..." << endl;
    }
    else if(i>=2){
        cout << A << " is the only one for you..." << endl;
    }
    else cout << "Momo... No one is for you ..." << endl;
    return 0;
}