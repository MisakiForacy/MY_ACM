#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
};
struct cmp{
    bool operator () (node a,node b){
        return a.a < b.a;
    }
};
int main(){
    // priority_queue<node,vector<node>,cmp>;
    
}