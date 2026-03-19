#include <bits/stdc++.h>
using namespace std;
void solve(int k,int x,int y,int ax,int ay){
    if (k==0) return;
    int hl = pow(2,k-1);
    if (x<=ax&&ax<x+hl&&y<=ay&&ay<y+hl){
        cout << y + hl << ' ' << x + hl << ' ' << 1 << '\n';
        solve(k-1,x,y,ax,ay);
        solve(k-1,x,y+hl,x+hl-1,y+hl);
        solve(k-1,x+hl,y+hl,x+hl,y+hl);
        solve(k-1,x+hl,y,x+hl,y+hl-1);
    } else if (x+hl<=ax&&ax<x+2*hl&&y<=ay&&ay<y+hl){
        cout << y + hl << ' ' << x + hl - 1 << ' ' << 2 << '\n';
        solve(k-1,x+hl,y,ax,ay);
        solve(k-1,x,y,x+hl-1,y+hl-1);
        solve(k-1,x,y+hl,x+hl-1,y+hl);
        solve(k-1,x+hl,y+hl,x+hl,y+hl);
    } else if (x<=ax&&ax<x+hl&&y+hl<=ay&&ay<y+2*hl){
        cout << y + hl - 1 << ' ' << x + hl << ' ' << 3 << '\n';
        solve(k-1,x,y+hl,ax,ay);
        solve(k-1,x,y,x+hl-1,y+hl-1);
        solve(k-1,x+hl,y,x+hl,y+hl-1);
        solve(k-1,x+hl,y+hl,x+hl,y+hl);
    } else{
        cout << y + hl - 1 << ' ' << x + hl - 1 << ' ' << 4 << '\n';
        solve(k-1,x+hl,y+hl,ax,ay);
        solve(k-1,x,y,x+hl-1,y+hl-1);
        solve(k-1,x,y+hl,x+hl-1,y+hl);
        solve(k-1,x+hl,y,x+hl,y+hl-1);
    }
}
int main(){
    int k,x,y;
    cin >> k >> y >> x;
    solve(k,1,1,x,y);
}