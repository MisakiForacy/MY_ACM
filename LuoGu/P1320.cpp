#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    string ss,s;
    int count = 0;
    cin >> ss;
    int n;
    n = ss.length();
    for(int i=1;i<n;i++){
        cin >> s;
        ss.append(s);
    }
    cout << n << " ";
    if(ss[0]-'0')cout << 0 << " ";
    for(int i=0;i<ss.length();i++){
        count++;
        if(ss[i]!=ss[i+1]){
            cout << count << " ";
            count = 0;
        }
    }
    return 0;
}