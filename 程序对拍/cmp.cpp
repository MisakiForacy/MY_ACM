#include<bits/stdc++.h>
#define Timelim 2000

using namespace std;
string ColorStr(int r,int g,int b,string str){
    if (0 <= r && r <= 255 && 0 <= g && g <= 255 && 0 <= b && b <= 255){
        return "\033[38;2;"+to_string(r)+";"+to_string(g)+";"+to_string(b)+"m"+str;
    } else{
        return "\x1b[0m" + str;
    }
}
int main(){
    // system("std.exe < in.txt > std.txt");
    // system("vio.exe < in.txt > vio.txt");
    system("g++ ../std.cpp -o std.exe");
    system("g++ ../vio.cpp -o vio.exe");
    system("g++ ../dat.cpp -o dat.exe");
    int n;
    printf("测试组数：");
    scanf("%d",&n);
    vector<string> res;
    for (int i = 1;i <= n;i ++){
        system("dat.exe > in.txt");
        system("vio.exe < in.txt > vio.txt");
        double begin = clock();
        printf("Running in test %d ...\n",i);
        system("std.exe < in.txt > std.txt");
        double end = clock();
        double t = end - begin;
        string info = "In Test "+to_string(i)+" Time : "+to_string(t) + " ms";
        if (system("fc std.txt vio.txt")){
            res.push_back(ColorStr(255,0,0,"Wrong Answer\n") + ColorStr(-1,-1,-1,info));
            system("std.exe < in.txt > ../Output.txt");
            system("vio.exe < in.txt > ../Answer.txt");
            break;
        } else if (t > Timelim){
            res.push_back(ColorStr(255,0,0,"Time Limited Exceeded\n") + ColorStr(-1,-1,-1,info));
        } else{
            res.push_back(ColorStr(0,255,0,"Accpeted\n") + ColorStr(-1,-1,-1,info));
        }
        system("cls");
    }
    for (int i = 0;i < res.size();i ++){
        cout << res[i] << '\n';
    }
    printf("\x1b[0m");
    return 0;
}