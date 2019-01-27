#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

set<string> dic;

int main(){
   freopen("10815.in","r",stdin);
   freopen("10815.out","w",stdout);
   string line;
   char word[201];
   while(getline(cin,line)){
      int j = 0;
      line+='.';
      loop(i,0,line.length()){
         if(isalpha(line[i]))
            word[i-j]=tolower(line[i]);
         else{
            if(i-j > 0){
               word[i-j] = '\0';
               dic.insert(word);
            }
            j = i+1;
         }
      }
   }
   loopit(it,dic.begin(),dic.end())
      cout<<*it<<endl;

   return 0;
}
