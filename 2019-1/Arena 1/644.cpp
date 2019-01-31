#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;
vector<string> bin;
int main(){
//   freopen("644.in","r",stdin);
//   freopen("644.out","w",stdout);
   string line;
   int cas = 0;
   bool ans;
   while(getline(cin,line)){
      if(line.length()!=0 && line[0]=='9'){
         sort(bin.begin(),bin.end());
         loop(i,0,bin.size()&&ans){
            loop(j,1,bin[i].length()+1){
               string sub = bin[i].substr(0,j);
               auto ind = lower_bound(bin.begin(),bin.end(),sub);
               int k = ind-bin.begin();
               if(ind != bin.end() && k != i && ((*ind) == sub)){
                  ans = false;
                  break;
               }
            }
         }
         if(ans)printf("Set %d is immediately decodable\n",++cas);
         else printf("Set %d is not immediately decodable\n",++cas);
         bin.clear();
         ans = true;
      }else bin.push_back(line);


   }
   return 0;
}
