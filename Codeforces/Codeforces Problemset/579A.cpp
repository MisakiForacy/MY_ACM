#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int x;
    cin >> x;
    bitset<64>b(x);
    cout << b.count() << '\n';
}