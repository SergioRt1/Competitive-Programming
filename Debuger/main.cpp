#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

map<string,string> words;

int main(){
   freopen("156.in","r",stdin);
   freopen("156.out","w",stdout);
   string line;
   while(getline(cin,line)){
      if(line.length() == 0)continue;
      if(line[0]=='#') break;
      stringstream ss(line);
      char low[80];
      while(ss>>line){
         loop(i,0,line.length()){
            low[i]=tolower(line[i]);
         }
         sort(low,low+line.length());
         low[line.length()]='\0';
         string lows = low;
         auto it = words.find(lows);
         if(it==words.end())
            words[lows]=line;
         else
            words[lows]="\0";
      }
   }
   loopit(it,words.begin(),words.end()){
      if( (it->Y)[0]!='\0')
         cout<<it->Y<<endl;
   }
   return 0;
}
