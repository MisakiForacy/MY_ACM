#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    vector<int> p = {1, 1, 1, 3};
    do {
        for (int i = 0;i < 4;i ++) cout << p[i] << ' ';
        cout << '\n';
        cnt ++;
    } while (next_permutation(p.begin(), p.end()));
    cout << cnt << '\n';
}