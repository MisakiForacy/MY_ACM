#include <bits/stdc++.h>
using namespace std;
int main(){
    int Ra,Ca,Rb,Cb;
    int i,j,k;
    int Multiply;
    cin >> Ra >> Ca;
    vector<vector<int>>A(Ra,vector<int>(Ca));
    for(i=0;i<Ra;i++){
        for(j=0;j<Ca;j++){
            cin >> A[i][j];
        }
    }
    cin >> Rb >> Cb;
    vector<vector<int>>B(Rb,vector<int>(Cb));
    for(i=0;i<Rb;i++){
        for(j=0;j<Cb;j++){
            cin >> B[i][j];
        }
    }
    if(Ca != Rb){
        cout << "Error: " << Ca << " != " << Rb << endl;
    }
    else{
        vector<vector<int>>C(Ra,vector<int>(Cb));
        for(i=0;i<Ra;i++){
            for(j=0;j<Cb;j++){
                Multiply = 0;
                for(k=0;k<Ca;k++){
                    Multiply += A[i][k] * B[k][j];
                }
                C[i][j] = Multiply;
            }
        }
        cout << Ra << " " << Cb << endl;
        for(i=0;i<Ra;i++){
            for(j=0;j<Cb-1;j++){
                cout << C[i][j] << " ";
            }
            cout << C[i][j] << endl;
        }
    }
}