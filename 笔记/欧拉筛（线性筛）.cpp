#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int) x.size())
using namespace std;
using LL = long long;

const int N = 1e6 + 10;

vector<int> s(N, 0);
vector<int> p;

void Euler(){
    for (int i = 2;i < N;i ++){
        if (!s[i]) p.push_back(i);
        for (int k = 0;k < siz(p) && i * p[k] < N;k ++){
            s[i * p[k]] = 1;
            if (i % p[k] == 0) break;
        }
    }
}

int main(){
    Euler();
    for (auto x : p){
        cout << x << ' ';
    }
    cout << '\n';
}