#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5,3,1,2,4};
    for (int i=0;i<5;i++){
        for (int j=1;j<5-i;j++){
            if (a[j] > a[j-1]){
                swap(a[j],a[j-1]);
            }
        }
    }
    for (int i=0;i<5;i++){
        cout << a[i] << " \n"[i==4];
    }
}