#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int n;
    int maxn = 0;
    vector<int>List,res;
    for(n = a;n <= b;n++){
        string num;
        int times = 0;
        num = to_string(n);
        while(num.length()!=1){
            int t = 1;
            for(int i=0;i<num.length();i++)t = t * (num[i] - '0');
            num = to_string(t);
            times++;
        }
        List.push_back(times);
        if(times>maxn)maxn = times;
    }
    cout << maxn << endl;
    for(int i=0;i<List.size();i++)if(List[i] == maxn)res.push_back(i+a);
    cout << res[0];
    for(int i=1;i<res.size();i++)cout << " " << res[i];
}