#include <bits/stdc++.h>

using namespace std;

int main () {
    // system("g++ gen.cpp -o gen");
    // system("g++ std.cpp -o std");
    // system("g++ my.cpp -o my");
    int T; cin >> T;
    for (int test = 1;test <= T;test ++) {
        system("./gen > in");
        system("./std < in > STD_");
        double begin = clock();
        system("./my < in > MY_");
        double end = clock();
        double Time = end - begin;
        if (system("diff STD_ MY_")) {
            cout << "Wrong Anser " << test << " : " << Time << " ms\n";
            break;
        } else {
            cout << "Accept " << test << " : " << Time << " ms\n";
        }
    }
}