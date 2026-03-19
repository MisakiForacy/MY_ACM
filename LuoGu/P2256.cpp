#include <bits/stdc++.h>
using namespace std;
map<string,string>Set;
string findx(string x){
    if (Set[x] != x){
        Set[x] = findx(Set[x]);
    }
    return Set[x];
}
void mergex(string a,string b){
    if(a!=b) Set[a] = b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N,M,K;
    string s,s1,s2;
    cin >> N >> M;
    for (int i=0;i<N;i++){
        cin >> s;
        Set[s] = s;
    }
    for (int i=0;i<M;i++){
        cin >> s1 >> s2;
        mergex(findx(s1),findx(s2));
    }
    cin >> K;
    for (int i=0;i<K;i++){
        cin >> s1 >> s2;
        if (findx(s1) == findx(s2)){
            cout << "Yes." << '\n';
        } else cout << "No." << '\n';
    }
    return 0;
}