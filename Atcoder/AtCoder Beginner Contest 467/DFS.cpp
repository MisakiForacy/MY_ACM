#include <bits/stdc++.h>
using namespace std;
int used[20],a[20],n;
long long ret=0;
bool flag;
void dfs(int x)
{
    int i;
    if(x > n)
    {
        flag=1;
        for(i=1;i<=n;i++)
            if(a[i]+i > n+2)
            {
                flag=0;
                break;
            }
        if(flag) ret++;
        return;
    }
    for(i=1;i<=n;i++)
        if(used[i]==0)
        {
            used[i]=1, a[x]=i;
            dfs(x+1);
            used[i]=0, a[x]=0;
        }
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<ret;
    return 0;
}
