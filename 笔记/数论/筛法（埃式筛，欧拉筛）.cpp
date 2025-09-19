#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+10;

int sieve[N];
int prime[N];

/*
埃拉托斯特尼筛法
对于任意一个大于 1 的正整数 n，
那么它的 x 倍就是合数（x > 1）。
利用这个结论，我们可以避免很多次不必要的检测。

如果我们从小到大考虑每个数，
然后同时把当前这个数的所有（比自己大的）倍数记为合数，
那么运行结束的时候没有被标记的数就是素数了。
*/
int Era(int n){
    int k = 0;
    for (int i=2;i*i<=n;i++){
        if (!sieve[i]){
            for (int j=i*i;j<=n;j+=i){
                sieve[j] = 1;
            }
        }
    }
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }
    }
    return k;
}

/*
欧拉筛法

*/
int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }   
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return k;
}

int main(){
    int n,len;
    cin >> n;
    // len = Era(n);
    len = Euler(n);
    // for (int i=0;i<len;i++){
    //     cout << prime[i] << " \n"[i==len-1];
    // }
    cout << len << '\n';
}   