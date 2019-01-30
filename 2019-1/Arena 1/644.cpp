#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;
vector<string> bin;
int main(){
   freopen("644.in","r",stdin);
   freopen("644.out","w",stdout);
   string line;
   int cas = 0;
   bool ans;
   while(getline(cin,line)){
      if(line.length()!=0 && line[0]=='9'){
         sort(bin.begin(),bin.end());
         loop(i,0,bin.size()){
            cout<<bin[i]<<endl;
            loop(j,1,bin[i].length()+1){
               cout<<bin[i]<<" ["<<j<<"] ="<<bin[i].substr(0,j)<<endl;
               if( && binary_search(bin.begin(),bin.end(),bin[i].substr(0,j))){
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
