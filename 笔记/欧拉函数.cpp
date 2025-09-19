#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

const int N = 1e6 + 10;

vector<int> s(N, 0), phi(N, 0);
vector<int> p;

/**
 * 用欧拉筛求欧拉函数，复杂度O(n)
 */

void Euler() {
    phi[1] = 1;
    for (int i = 2;i < N;i ++) {
        if (!s[i]) {
            p.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0;j < siz(p) && i * p[j] < N;j ++) {
            s[i * p[j]] = 1;
            phi[i * p[j]] = phi[i] * phi[p[j]];
            if (i % p[j] == 0) break;
        }
    }
}

int main(){
    Euler();
    for (int i = 1;i <= 10;i ++){
        cout << phi[i] << " \n"[i == 10];
    }
}