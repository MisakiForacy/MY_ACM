#include <bits/stdc++.h>
using namespace std;
static vector<vector<int>>Tree;
static vector<int>q;
static inline void Traversal(int root);
int main(){
    string res = "yes";
    int n,x,head,maxn = -1;
    cin >> n;
    Tree.resize(n);
    for(int i=0;i<n;i++){
        cin >> x;
        if(x!=0)Tree[x-1].push_back(i+1);
        else head = i+1;
    }
    for(int i=0;i<n;i++){
        if(int(Tree[i].size())>maxn)maxn = Tree[i].size();
    }
    
    for(int i=0;i<n;i++){
        if(Tree[i].size()!=0 && Tree[i].size()!=maxn)res = "no";
    }
    Traversal(head);
    cout << maxn << " " << res << endl;
    for(int i=0;i<n-1;i++){
        cout << q[i] << " ";
    }
    cout << q[n-1] << endl;
}
static inline void Traversal(int root){
    q.push_back(root);
    if(Tree[root-1].size()){
        for(int i=0;i<Tree[root-1].size();i++){
            Traversal(Tree[root-1][i]);
        }
    }
}