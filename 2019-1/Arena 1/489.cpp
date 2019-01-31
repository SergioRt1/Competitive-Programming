#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
   freopen("489.in","r",stdin);
   freopen("489.out","w",stdout);
   int n,cas = 0;
   while(scanf("%d",&n)==1 && n!=-1){
      string s1,s2;
      cin>>s1>>s2;
      int fa = 0;

      loop(i,0,s2.size()&&fa <= 6 && s1 != ""){
         if(s1.find(s2[i])!=-1){
            auto dir = remove(s1.begin(),s1.end(),s2[i]);
            s1.erase(dir,s1.end());
         }else fa++;
      }
      printf("Round %d\n",++cas);
      if(fa == 7)
         puts("You lose.");
      else if(s1=="")
         puts("You win.");
      else
         puts("You chickened out.");

   }
   return 0;
}
