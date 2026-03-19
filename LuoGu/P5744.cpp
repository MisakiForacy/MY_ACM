#include <bits/stdc++.h>
using namespace std;
struct info{
    string name;
    int age;
    int score;
};
int main(){
    int n,i;
    cin >> n;
    vector<info>a(n);
    for(i=0;i<n;i++){
        cin >> a[i].name >> a[i].age >> a[i].score;
        a[i].age++;
        a[i].score = a[i].score * 1.2;
        if(a[i].score>600)a[i].score = 600;
    }
    for(i=0;i<n;i++){
        cout << a[i].name << " " << a[i].age << " " << a[i].score << endl;
    }
}