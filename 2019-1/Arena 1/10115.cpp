#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

vector<string> cla;
vector<string> ma;

int main(){
//   freopen("10115.in","r",stdin);
//   freopen("10115.out","w",stdout);
   int n;
   string l1,l2;
   while(scanf("%d",&n)==1&&n){
      ma.clear();
      cla.clear();
      cla.resize(n);
      ma.resize(n);
      getline(cin,l1);
      loop(i,0,n){
         getline(cin,l1);
         getline(cin,l2);
         cla[i]=l1;
         ma[i]=l2;
      }
      getline(cin,l1);
      loop(i,0,n){
         bool can=true;
         int j;
         while(can){
            can = false;
            j = l1.find(cla[i]);
            if(j != -1){
               can = true;
               l1 = l1.replace(j,cla[i].length(),ma[i]);
            }
         }
      }
      cout<<l1<<endl;
   }
   return 0;
}
