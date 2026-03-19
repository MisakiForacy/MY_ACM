#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main () {
    system ("g++ KK.cpp -o KK");
    system ("g++ K.cpp -o K");
    system ("g++ K_gen.cpp -o K_gen");
    system ("./K_gen > in");
    system ("./K < in > K_out");
    system ("./KK < in > KK_out");
    system ("")
}