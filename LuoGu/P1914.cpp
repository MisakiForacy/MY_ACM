#include <iostream>
#include <string>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i=0;i<s.length();i++){
        cout << char((s[i]-'a' + n)%26+'a');
    }
}