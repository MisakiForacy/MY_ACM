#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
static inline bool isprime(int num);
int main(){
    int n,count,maxc = -INF;
    int a[100],j,Multiply;
    cin >> n;
    if(isprime(n)){
        cout << 1 << endl << n << endl;
    }
    else{
        for(int i=2;i<=n;i++){
            count = 0;
            Multiply = 1;
            for(j=i;j<=n;j++){
                Multiply *= j;
                if(n%Multiply==0){
                    count++;
                }
                else break;
            }
            if(count>maxc){
                maxc = count;
                for(int i=j-maxc-1;i<j;i++){
                    a[maxc-(j-i)] = i;
                }
            }
        }
        cout << maxc << endl;
        for(int i=0;i<maxc-1;i++){
            cout << a[i] << "*";
        }
        cout << a[maxc-1];
    }
    return 0;
}
static inline bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0)return false;
    }
    return true;
}