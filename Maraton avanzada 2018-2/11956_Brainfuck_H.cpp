#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

int memo[100];

int main(){
//    freopen("H.txt","r",stdin);
//    freopen("ho.txt","w",stdout);
    int cas;
    string line;
    scanf("%d",&cas);getline(cin,line);
    loop(ca,0,cas){
        memset(memo,0,sizeof memo);
        getline(cin,line);
        int curr = 0;
        loop(i,0,line.length()){
            if(line[i] == '>'){
                curr = (100+curr+1)%100;
            }else if(line[i] == '<'){
                curr = (100+curr-1)%100;
            }else if(line[i] == '+'){
                memo[curr] = (256+memo[curr]+1)%256;
            }else if(line[i] == '-'){
                memo[curr] = (256+memo[curr]-1)%256;
            }
        }
        printf("Case %d:",ca+1);
        loop(i,0,100)printf(" %02X",memo[i]);
        puts("");

    }
    return 0;
}
