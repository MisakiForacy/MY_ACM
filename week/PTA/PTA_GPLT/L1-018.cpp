#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int hh,mm,tt,i;
    scanf("%d:%d",&hh,&mm);
    tt = hh*60+mm;
    if(tt<=720)cout<<"Only "<<(hh<10?"0":"")<<hh<<":"<<(mm<10?"0":"")<<mm<<".  Too early to Dang.";
    else{
        for(i=0;i<tt/60-12+(tt%60?1:0);i++)cout<<"Dang";
    }
    cout << endl;
    return 0;
}