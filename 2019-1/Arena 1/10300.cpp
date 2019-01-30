#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
//   freopen("10300.in","r",stdin);
//   freopen("10300.out","w",stdout);
   int n,f;
   scanf("%d",&n);
   loop(ca,0,n){
     scanf("%d",&f);
     large ans=0;
     loop(i,0,f){
          int t,a,e;
          scanf("%d%d%d",&t,&a,&e);
          ans+=t*e;
     }
     cout<<ans<<endl;


   }
   return 0;
}
