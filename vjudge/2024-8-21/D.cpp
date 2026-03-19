#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;

vector<int> sieve(N,0);

void Era(int p,int b){
    for (int i=2;i<=b;i++){
        if (!sieve[i] && i >= p){
            for (int j=i;j<=b;j+=i){
                if (sieve[j]>1 && sieve[j]!=i){
                    int temp = sieve[j];
                    for (int k=2;k<=b;k++){
                        if (sieve[k]==temp){
                            sieve[k] = i;
                        }
                    }
                }
                sieve[j] = i;
            }
        } else if (!sieve[i]){
            for (int j=i;j<=b;j+=i){
                sieve[j] = 1;
            }
        }
    }
}

int main(){
    int a,b,p;
    cin >> a >> b >> p;
    set<int>st;
    Era(p,b);
    int cnt = 0;
    for (int i=a;i<=b;i++){
        st.insert(sieve[i]);
        if (sieve[i]==1) cnt ++;
    }
    cout << st.size()+cnt-(cnt?1:0) << '\n';
}