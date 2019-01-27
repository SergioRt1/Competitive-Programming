#include<bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)

using namespace std;

char tab[26];
char tabn[5][5]

typedef unordered_map<int,int> um;
typedef vector<int> vi;

um sol;

int dir[][] = {{-1,-2,{-2,-1},{-2,1},{-1,2},{}

int pas(){
    int mask = 0;
    loop(i,0,25){
        if(tab[i] == ' '){
            mask |= i<<25;
            continue;
        }
        mask |= (tab[i]=='1')<<i*2;
    }
    return mask;
}

void decode(int mask){
    loop(i,0,25){
        tab[i] = mask>>i+'0';
    }
    tab[mask>>25]=' ';
}

int main(){
    int n;
    char tm;
    vi cur;
    scanf("%d",&n);
    sol.clear();
    sol[13957489152] = 0; //01100111111111011100110001000000000
    tab
    loop(i,0,10){
        vi next;
        loop(j,0,)
        tab[mask>>25];

    }
    loop(cas,0,n){
        loop(i,0,5)loop(j,0,5){
            cin>>tabn[i][j];
        }
        for(int i = 4; i>-1;i--)loop(j,0,5){
            tab[i*5+j] = ;
        }
    }
    bfs(pas());

    return 0;
}
