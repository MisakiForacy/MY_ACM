#include <bits/stdc++.h>
using namespace std;

static vector<int>Post;
static vector<int>Sequence;
static inline void CreateSequence(int i,int len);

int main(){
    int n;
    cin >> n;
    Post.resize(n+1);
    Sequence.resize(n+1);
    for(int i=1;i<=n;i++)cin >> Post[i];
    CreateSequence(1,n);
    for(int i=1;i<n;i++)cout << Sequence[i] << " ";
    cout << Sequence[n] << endl;
}

static inline void CreateSequence(int i,int len){
    static int k = 0;
    if(i>len)return;
    CreateSequence(i * 2,len);
    CreateSequence(i * 2 + 1,len);
    Sequence[i] = Post[++k];
}