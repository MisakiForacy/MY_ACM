#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>ar;
bool check(int n){
    for (int i=2;i<=sqrt(n);i++){
        if (!(n%i)) return 0;
    } return 1;
}
void pp(){
    ar.push_back(5),ar.push_back(7),ar.push_back(11);
    for (int n1=1;n1<=9;n1+=2){
        for (int n2=0;n2<=9;n2++){
            int s = n1 * 100 + n2 * 10 + n1;
            if (check(s)) ar.push_back(s);
        }
    }
    for (int n1=1;n1<=9;n1+=2){
        for (int n2=0;n2<=9;n2++){
            for (int n3=0;n3<=9;n3++){
                int s = n1 * 10000 + n2 * 1000 + n3 * 100 + n2 * 10 + n1;
                if (check(s)) ar.push_back(s); 
            }
        }
    }
    for (int n1=1;n1<=9;n1+=2){
        for (int n2=0;n2<=9;n2++){
            for (int n3=0;n3<=9;n3++){
                for (int n4=0;n4<=9;n4++){
                    int s = n1*1000000 + n2*100000 + n3*10000 + n4*1000 + n3*100 + n2*10 + n1;
                    if (check(s)) ar.push_back(s);
                }
            }
        }
    }
    for (int n1=1;n1<=9;n1+=2){
        for (int n2=0;n2<=9;n2++){
            for (int n3=0;n3<=9;n3++){
                for (int n4=0;n4<=9;n4++){
                    for (int n5=0;n5<=9;n5++){
                        int s = n1*100000000+n2*10000000+n3*1000000+n4*100000+n5*10000+n4*1000+n3*100+n2*10+n1;
                        if (check(s)) ar.push_back(s);
                    }
                }
            }
        }
    }
}
int main(){
    int a,b;
    cin >> a >> b;
    pp();
    for (int i=0;i<ar.size();i++){
        if (a<=ar[i]&&ar[i]<=b){
            cout << ar[i] << '\n';
        } else if (ar[i]>b){
            break;
        }
    }
}