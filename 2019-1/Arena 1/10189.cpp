#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int n,m;
char tab[105][105];

int dx[] = {1,1,1,0,  0,-1,-1,-1};
int dy[] = {1,0,-1,1, -1,1,0,-1};

int main(){
//   freopen("10189.in","r",stdin);
//   freopen("10189.out","w",stdout);
   int cas = 0;
   while(scanf("%d %d", &n,&m)==2 && (n|m)){
      if(cas != 0)puts("");
      cas++;
      loop(i,0,n)loop(j,0,m){
         cin>>tab[i][j];
         if(tab[i][j]=='.')tab[i][j]='0';
      }
      loop(i,0,n)loop(j,0,m){
         if(tab[i][j]=='*')
            loop(k,0,8){
               int X = i+dx[k];
               int Y = j+dy[k];
               if(0<=X&&X<n && 0<=Y&&Y<m && tab[X][Y]!= '*'){
                  tab[X][Y]++;
               }
            }
      }
      printf("Field #%d:\n",cas);
      loop(i,0,n){
         loop(j,0,m)putchar(tab[i][j]);
         putchar('\n');
      }
   }
   return 0;
}
