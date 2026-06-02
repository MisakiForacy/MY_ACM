#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    multiset<int> p = {1, 2, 3, 3, 6};
    auto it = p.lower_bound(8);
    cout << *it << '\n';
}