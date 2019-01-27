#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

int main(){
//   freopen("494.in","r",stdin);
//   freopen("494.out","w",stdout);
   string line;
   while(getline(cin,line)){
      int ans = 0;
      bool pal = false;
      loop(i,0,line.length()){
         if(!pal && isalpha(line[i])){
            ans++;
            pal = true;
//            printf("%d  ",i);
         }
         if(pal && !isalpha(line[i]))pal = false;
      }
      printf("%d\n",ans);
   }
   return 0;
}
