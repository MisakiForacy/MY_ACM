#include <bits/stdc++.h>
using namespace std;

struct Time{
    int start_time;
    int end_time;
};

static inline bool cmp(const Time&a,const Time&b){
    return a.start_time<b.start_time;
}

int main(){
    int n;
    int h1,m1,s1,h2,m2,s2;
    int hh,mm,ss;
    int t1,t2;
    int i,j;
    cin >> n;
    vector<Time>tt(n);
    for(i=0;i<n;i++){
        scanf("%d:%d:%d - %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
        t1 = h1*3600 + m1*60 + s1;
        t2 = h2*3600 + m2*60 + s2;
        // cout << t1 << ":" << t2 << endl;
        tt[i].start_time = t1;
        tt[i].end_time = t2;
    }
    sort(tt.begin(),tt.end(),cmp);
    if(tt[0].start_time!=0){
        hh = tt[0].start_time/3600;
        mm = tt[0].start_time%3600/60;
        ss = tt[0].start_time%60;
        printf("00:00:00 - %02d:%02d:%02d\n",hh,mm,ss);
    }
    for(i=0;i<n-1;i++){
        if(tt[i].end_time!=tt[i+1].start_time){
            h1 = tt[i].end_time/3600;
            m1 = tt[i].end_time%3600/60;
            s1 = tt[i].end_time%60;
            h2 = tt[i+1].start_time/3600;
            m2 = tt[i+1].start_time%3600/60;
            s2 = tt[i+1].start_time%60;
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
        }
    }
    if(tt[i].end_time!=86399){
        hh = tt[i].end_time/3600;
        mm = tt[i].end_time%3600/60;
        ss = tt[i].end_time%60;
        printf("%02d:%02d:%02d - 23:59:59\n",hh,mm,ss);
    }
}