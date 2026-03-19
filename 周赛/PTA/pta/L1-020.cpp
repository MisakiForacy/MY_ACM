#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K,ID,M;
    int i,j;
    bool flag = true;
    vector<int>a(100001,0);
    vector<int>b(100001,0);
    cin >> N;
    for(i=0;i<N;i++){
        cin >> K;
        for(j=0;j<K;j++){
            cin >> ID;
            if(K!=1&&a[ID]==0)a[ID] = 1;
        }
    }
    cin >> M;
    int k=0;
    for(i=0;i<M;i++){
        cin >> ID;
        if(a[ID]==0){
            b[k++] = ID;
            a[ID] = 1;
        }
    }
    if(k==0)cout << "No one is handsome" << endl;
    else{
        for(i=0;i<k-1;i++){
            printf("%05d ",b[i]);
        }
        printf("%05d",b[i]);
    }
}