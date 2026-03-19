#include <bits/stdc++.h>
using namespace std;

int main () {
    system ("g++ spj.cpp -o spj");
    system ("g++ dat.cpp -o dat");
    system ("g++ std.cpp -o std");
    int n;
    cin >> n;
    while (n --) {
        system ("./dat > in");
        system ("./std < in > out");
        system ("cat in out > new");
        system ("./spj < new");
    }
}