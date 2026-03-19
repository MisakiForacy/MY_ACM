#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    vector<int> p = {1,0,2,3,4,5,6,7,8,9,10,11};
    do{
        int x = 0;
        for (int i=0;i<p.size();i++){
            x ^= p[i];
        }
        if (x > 0){
            cout << x << '\n';
            for (int i=0;i<p.size();i++){
                cout << p[i] << " \n"[i==p.size()-1];
            }
            break;
        }
    } while (next_permutation(p.begin(),p.end()));
}