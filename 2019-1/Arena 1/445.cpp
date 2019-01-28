#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
//   freopen("445.in","r",stdin);
//   freopen("445.out","w",stdout);
   string line;
   while(getline(cin,line)){
      int m = line.length();
      int curr = 0;
      loop(i,0,m){
         if(isdigit(line[i]))curr+=line[i]-'0';
         else{
            char c;
            if(line[i]=='b')c=' ';
            else if(line[i]=='!')puts("");
            else c=line[i];
            loop(j,0,curr){
               printf("%c",c);
            }
            curr=0;
         }
      }
      puts("");
   }
   return 0;
}
