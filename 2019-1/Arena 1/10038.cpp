#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

bool values[3005];

int main(){
//   freopen("10038.in","r",stdin);
//   freopen("10038.out","w",stdout);
   int n,ac,pas;
   while(scanf("%d",&n)==1){
      scanf("%d",&pas);
      memset(values,false,sizeof values);
      bool jolly = true;
      loop(k,1,n){
         scanf("%d",&ac);
         values[abs(pas-ac)]=true;
//         printf("%d %d = %d\n",pas,ac,abs(pas-ac));
         pas = ac;
      }
      loop(i,1,n){
         jolly &= values[i];
      }

      if(jolly)puts("Jolly");
      else puts("Not jolly");
   }
   return 0;
}
