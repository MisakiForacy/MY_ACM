#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int s1[100],s2[100];
int str(ll num,int s1[]){
    int len = 0;
    while(num!=0){
        s1[len++]=num%10;
        num=num/10;
    }
    return len;
}
int Multiply(int s1[],int s2,int len){
    int x = 0,j=1,i=0;
    while(i<len){
        s1[i] = s1[i] * s2;
        i++;
    }
    x = s1[0] / 10;
    if(j==len&&x!=0)len++;
    while(x!=0||j<len){
        s1[j] = s1[j] + x;
        s1[j-1] = s1[j-1] % 10;
        x = s1[j] / 10;
        if(j==len)len++;
        j++;
    }
    return len;
}
int Add(int s1[],int s2[],int len_s1,int len_s2){
    int c,len;
    len = max(len_s1,len_s2);
    c = 0;
    for(int i=0;i<len;i++){
        s1[i] = s1[i] + s2[i] + c;
        c = s1[i] / 10;
        s1[i] = s1[i] % 10;
    }
    if(c!=0){
        s1[len] = c;
        len++;
    }
    return len;
}
int main(){
    int n,len_s2=1,len_s1=1;
    cin >> n;
    s1[0] = 1;s2[0] = 1;
    for(int i=2;i<=n;i++){
        len_s2 = Multiply(s2,i,len_s2);
        len_s1 = Add(s1,s2,len_s2,len_s1);
    }
    for(int i=len_s1-1;i>-1;i--){
        cout << s1[i];
    }
}