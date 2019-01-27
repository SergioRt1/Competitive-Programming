#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

unordered_set<string> dic;
vector<string> vec;
int main(){
//   freopen("10887.in","r",stdin);
//   freopen("10887.out","w",stdout);
   int cas;
   scanf("%d",&cas);
   string tm;
   loop(ca,0,cas){
      dic.clear();
      vec.clear();
      int a,b;
      scanf("%d %d",&a,&b);
      getline(cin,tm);
      loop(i,0,a){
         getline(cin,tm);
         vec.push_back(tm);
      }
      loop(i,0,b){
         getline(cin,tm);
         loop(j,0,a)
            dic.insert(vec[j]+tm);
      }
      printf("Case %d: %d\n",ca+1,dic.size());
   }
   return 0;
}
