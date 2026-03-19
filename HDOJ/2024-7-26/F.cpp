#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
struct haha{
    int val,idx;
    bool operator < (const haha &that) const {
        if (val != that.val){
            return val > that.val;
        } else if (idx != that.idx){
            return idx > that.idx;
        }
    }
};

int a[N],b[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        
        map<int,int> mp;
        priority_queue<haha> q;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            b[i] = 1;
            haha temp;
            temp.val = a[i];
            temp.idx = i;
            q.push(temp);
            
            mp[i] = 1;
        }

        int ans = 0;
        while (q.size()>1){
            haha t = q.top();
            q.pop();

            int cur = t.idx;
            int l = mp.lower_bound(cur);
            int r = upper_bound(mp.begin(),mp.end(),cur).first; 

        	mp.erase(cur);
        	
        	int k;
        	if(l>=1 && r<=n){
        		k = a[l]>a[r]?r:l;
			}
			else if(l>=1){
				k = l;
			}
			else if(r<=n){
				k = r;
			}
			
			b[k]+=b[cur];
			if(a[k]!=a[cur]){
            	ans+=b[cur];
            }
			
        	
        }

        cout<<"ans:";
        cout<<ans<<endl;
    }
}
