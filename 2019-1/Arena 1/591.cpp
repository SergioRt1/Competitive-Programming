#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

int mat[60];

int main(){
//   freopen(".in","r",stdin);
    int cas = 0,n;
   while(scanf("%d",&n)==1 & n != 0){
      cas++;
      int total = 0;
      loop(i,0,n){
         scanf("%d",&mat[i]);
         total += mat[i];
      }
      int avg = total/n;
      int ans = 0;
      loop(i,0,n)
         if(mat[i] > avg)
            ans += mat[i]-avg;
      printf("Set #%d\nThe minimum number of moves is %d.\n\n",cas,ans);
   }
   return 0;
}
