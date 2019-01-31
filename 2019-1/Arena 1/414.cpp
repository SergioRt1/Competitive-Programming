#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int le[25];
int ri[25];
int dif[25];

int main(){
//   freopen("414.in","r",stdin);
//   freopen("414.out","w",stdout);
   int n;
   char c;
   string line;
   while(scanf("%d",&n)==1&&(n)){
      memset(le,0,sizeof le);
      memset(ri,0,sizeof ri);
      getline(cin,line);
      loop(i,0,n){
         getline(cin,line);
         bool hole = false;
         loop(j,0,25){
            if(line[j]!='X'){
               if(!hole){
                  hole=true;
                  le[i]=j;
               }
               ri[i]=j;
            }
         }
         if(!hole)le[i]=1;
      }
      int lim = 1<<30;
      loop(i,0,n){
         dif[i]=ri[i]-le[i];
         lim=min(lim,dif[i]);
      }
      int ans = 0;
      loop(i,0,n)
         ans += dif[i]-lim;
      printf("%d\n",ans);
   }
   return 0;
}
