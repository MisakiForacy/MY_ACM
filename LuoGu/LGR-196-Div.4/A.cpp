#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int y,m;
    cin >> y >> m;
    if (y==2016){
        cout << m-8+1 << '\n';
    } else{
        cout << 12-8 + (y-2016-1)*12 + m +1 << '\n';
    }
}