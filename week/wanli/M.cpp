#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
static inline bool Check(vector<int>arr);
int main(){
    int n,i,j;
    int maxn = -INF;
    cin >> n;
    vector<int>arr(n);
    for(i=0;i<n;i++)cin >> arr[i];
    while(Check(arr)){
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(arr[i]>0 && arr[i]==arr[j]){
                    arr[i] = arr[i]<<1;
                    arr[j] =0;
                    j = i + 1;
                }
            }
        }
    }
    for(i=0;i<n;i++){
        if(arr[i]>maxn)maxn = arr[i];
    }
    cout << maxn << endl;
    return 0;
}
static inline bool Check(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i] != 0 && arr[i] == arr[j])return true;
        }
    }
    return false;
}