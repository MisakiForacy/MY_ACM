#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    int n;
    cin >> t;
    while(t --){
        cin >> n;
        for(int i = 0; i < n * 2; i ++){
            for(int j = 0; j < n * 2; j ++){
                cout << ".#"[(i % 4 < 2 && j % 4 < 2) || (i % 4 >= 2 && j % 4 >= 2)];
            }
            cout << endl;
        }
    }
}