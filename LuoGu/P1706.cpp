#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>ar(n);
    for (int i=0;i<n;i++){
        ar[i] = i + 1;
    }
    do{
        for (int i=0;i<n;i++){
            printf("%5d",ar[i]);
        }
        printf("\n");
    }while(next_permutation(ar.begin(),ar.end()));
}