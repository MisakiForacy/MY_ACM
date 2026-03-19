#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 7;
    system("1.cpp -o std.exe");
    for (int i = 1;i <= T;i ++) {
        string cmd, cmp, in = "candy", out = "candy", name;
        in.push_back(char(i ^ 48));
        out.push_back(char(i ^ 48));
        name.push_back(char(i ^ 48));
        in += ".in";
        out += ".ans";
        cmd = "./std.exe < " + in + " > " + name;
        
    }
}