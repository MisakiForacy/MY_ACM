#include <iostream>
using namespace std;

const int N = 110;
int main() {
    int n;
    cin >> n;
    long long catalan[N] = {0};
    catalan[0] = 1; 
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] = (catalan[i] + catalan[j] * catalan[i - j - 1]);
        }
    }
    
    cout << catalan[n] << endl;
    return 0;
}