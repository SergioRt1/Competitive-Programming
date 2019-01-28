#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second


using namespace std;

typedef long long large;

map<string,int>girls;

int main(){
//   freopen("10420.in","r",stdin);
//   freopen("10420.out","w",stdout);
   int n;
   string line;
   scanf("%d",&n);
   getline(cin,line);
   loop(i,0,n){
      getline(cin,line);
      int m = line.length();
      string country;
      stringstream ss(line);
      ss>>country;
      auto it = girls.find(country);
      if(it != girls.end())
         girls[country]++;
      else{
         girls[country]=1;
      }
   }
   loopit(it,girls){
      cout<<it->X<<" "<<it->Y<<endl;
   }
   return 0;
}
