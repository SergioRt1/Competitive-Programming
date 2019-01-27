#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

char mat[30][30];
int N,M;

int dx[8] = {-1,-1,-1,0, 0,1,1,1};
int dy[8] = {-1,0,1,-1,  1,-1,0,1};


int dfs(int i, int j){
    int ans = 1;
    int X,Y;
    loop(k,0,8){
        X = dx[k]+i;
        Y = dy[k]+j;
        if( 0 <= X && X < N && 0 <= Y && Y < M && mat[X][Y]=='1'){
            mat[X][Y] = '.';
            ans += dfs(X,Y);
        }
    }
    return ans;
}

int main(){
//    freopen("c.txt","r",stdin);
    int cas;
    scanf("%d",&cas);
    string line;
    getline(cin,line); //linea cas 1
    getline(cin,line); //blank 0
    loop(ca,0,cas){
        int i = 0;
        if(ca != 0)puts("");
        while(true){
            getline(cin,line);
            if(line.length() == 0)break;
            M = line.length();
            loop(j,0,M)mat[i][j] = line[j];
            i++;
        }
        N = i;
        int maxv = 0;
        loop(i,0,N)loop(j,0,M){
            if(mat[i][j] == '1'){
                mat[i][j] = '.';
                maxv = max(maxv,dfs(i,j));
            }
        }
        printf("%d\n",maxv);
    }
    return 0;
}
