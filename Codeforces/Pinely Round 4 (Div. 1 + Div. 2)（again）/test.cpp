#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Point { LL x, y; };
Point operator - (Point a, Point b){ return {a.x-b.x, a.y-b.y}; }
LL cross(Point a, Point b){ return a.x*b.y - a.y*b.x; }

vector<Point> p;
int check(Point a,Point b,Point c){
    return cross(a-b, c-a) > 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    p.resize(n);
    for(int i=0;i<n;i++) cin >> p[i].x >> p[i].y;

    vector<char> opend(n,0);
    for(int i=0;i<n;i++){
        int L=(i-1+n)%n, R=(i+1)%n;
        int Lup=0, Rup=0, Ldown=0, Rdown=0, open=0;
        while(1){
            if(opend[L]){ open=1; break; }
            if(p[L].y > p[i].y){ Lup=1; break; }
            if(p[L].y < p[i].y){ Ldown=1; break; }
            L=(L-1+n)%n;
        }
        if(open || Ldown) continue;
        while(1){
            if(opend[R]){ open=1; break; }
            if(p[R].y > p[i].y){ Rup=1; break; }
            if(p[R].y < p[i].y){ Rdown=1; break; }
            R=(R+1)%n;
        }
        if(open || Rdown) continue;
        if(Lup && Rup){
            if(check(p[i],p[L],p[R]) || L==R){
                opend[i]=1;
                cerr << "marked: i=" << i << "  (" << p[i].x << ',' << p[i].y << ")\n";
            }
        }
    }
    cout << accumulate(opend.begin(),opend.end(),0) << '\n';
    return 0;
}