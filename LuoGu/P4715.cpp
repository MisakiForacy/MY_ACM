#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,i;
    cin >> n;
    t = pow(2,n);
    map<int,int>teams;
    vector<int>round(t);
    vector<int>next_round(pow(2,n-1));
    for(i=0;i<t;i++){
        cin >> round[i];
        teams[round[i]] = i+1;
    }
    for(int r=0;r<n;r++){
        for(i=0;i<t;i+=2){
            next_round[i/2] = max(round[i],round[i+1]);
            // cout << next_round[i/2] << " ";
        }
        // cout << endl;
        n--;
        t = pow(2,n);
        round.resize(t);
        for(i=0;i<t;i++){
            round[i] = next_round[i];
            // cout << round[i] <<  " ";
        }
        next_round.resize(pow(2,n-1));
    }
    cout << teams[min(round[0],round[1])] << endl;
    return 0;
}