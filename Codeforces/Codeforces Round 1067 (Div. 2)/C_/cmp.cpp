#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main () {
    int T;
    cin >> T;
    while (T --) {
        system("./gen > in");
        system("./std < in > std_");
        system("./my < in > my_");
        int ok = system("diff std_ my_");
        cout << ok << '\n';
        if (ok) break;
    }
}