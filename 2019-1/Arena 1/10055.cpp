#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

int main(){
   large a,b;
   while(scanf("%lld %lld",&a,&b)==2){
      if(a > b) printf("%lld\n", a - b);
      else printf("%lld\n", b - a);
   }
   return 0;
}
