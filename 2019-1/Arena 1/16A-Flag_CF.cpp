#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

int main(){
//   freopen(".in","r",stdin);
//   freopen(".out","w",stdout);
   int n,m;
   scanf("%d %d",&n,&m);
   char last = 100;
   bool fin = false;
   loop(i,0,n){
      if(fin)break;
      char curr,col;
      cin>>curr;
      loop(j,1,m){
         cin>>col;
         if(curr != col || col == last){
            fin = true;
            break;
         }
      }
      if(curr == last){
         fin = true;
         break;
      }
      last = curr;
   }
   if(!fin)puts("YES");
   else puts("NO");
   return 0;
}
