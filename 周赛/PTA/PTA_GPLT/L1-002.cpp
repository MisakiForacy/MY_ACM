#include <iostream>
#include <vector>
typedef long long ll;
typedef double db;
using namespace std;
int main(){
    int n,h=0,i,j;
    char s;
    cin >> n >> s;
    while(2*(h+1)+(h+1)*(h+1)<=(n-1)/2){
        h++;
    }
    vector<vector<char>>a(h*2+1,vector<char>(2*h+1,' '));
    for(i=0;i<h;i++){
        for(j=i;j<2*h-i+1;j++){
            a[i][j] = s;
        }
    }
    a[i][h] = s;
    for(i=h+1;i<2*h+1;i++){
        for(j=2*h-i;j<i+1;j++){
            a[i][j] = s;
        }
    }
    for(i=0;i<h;i++){
        for(j=0;j<2*h-i+1;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    for(j=0;j<=h;j++)cout << a[i][j];
    cout << endl;
    for(i=h+1;i<2*h+1;i++){
        for(j=0;j<i+1;j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << n-4*h-2*h*h-1;
}