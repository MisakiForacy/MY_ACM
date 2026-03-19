#pragma once
#include <bits/stdc++.h>
#define N 100000
using namespace std;
void change(int num[],char s[]){
    int i,len = strlen(s);
    for(i=len-1;i>-1;i--){
        num[len-i-1] = s[i] - '0';
    }
}
int add(int a[],int b[],int len){
    int i,x=0;
    for(i=0;i<len;i++){
        a[i] = a[i] + b[i] + x;
        x = a[i] / 10;
        a[i] = a[i] % 10;
    }
    if(x!=0){
        a[len] = x;
        len++;
    }
    return len;
}
int main(){
    int n,i,j;
    int len;
    int num1[N]={},num2[N]={},num3[N]={};
    cin >> n;
    len = 1;
    for(i=1;i<=n;i++){
        for(j=0;j<len;j++){
            num3[j] = num1[j];
        }
        if(i==1)num1[0]=1;
        else if(i==2)num1[0]=2,num2[0]=1;
        else{
            len = add(num1,num2,len);
        }
        for(j=0;j<len;j++){
            num2[j] = num3[j];
        }
    }
    for(i=len-1;i>-1;i--){
        cout << num1[i] ;
    }
}