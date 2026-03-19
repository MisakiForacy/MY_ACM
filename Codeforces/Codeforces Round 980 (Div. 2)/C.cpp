#include <bits/stdc++.h>
using namespace std;
int main(){
    struct node{
        int x,y;
        bool operator < (const node&that) const {
            if (min(x,y) != min(that.x,that.y)){
                return min(x,y) < min(that.x,that.y);
            }
            return max(x,y) < max(that.x,that.y);
        }
    };
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        vector<node> a(n);
        for (int i=0;i<n;i++){
            cin >> a[i].x >> a[i].y;
        }
        sort(a.begin(),a.end());
        for (int i=0;i<n;i++){
            cout << a[i].x << ' ' << a[i].y << " \n"[i==n-1];
        }
    }    
}

// 1 4
// 2 3