#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;
typedef pair<int,int> ii;

bool mat[505][505];

int main(){
   freopen("10703.in","r",stdin);
   freopen("10703.out","w",stdout);
   int w,h,n;
   while(scanf("%d%d%d",&w,&h,&n)==3&&(w|h|n)){
      memset(mat,true,sizeof mat);
      int x1,y1,x2,y2;
      loop(i,0,n){
         scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
         if(x1>x2)swap(x1,x2);
         if(y1>y2)swap(y1,y2);
         x1--;y1--;
         loop(i,x1,x2)loop(j,y1,y2)mat[i][j] = false;
      }
      int ans = 0;
      loop(i,0,w)loop(j,0,h)if(mat[i][j])ans++;
      if(ans==0)puts("There is no empty spots.");
      else if(ans==1)puts("There is one empty spot.");
      else printf("There are %d empty spots.\n",ans);
   }
   return 0;
}
