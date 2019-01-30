#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
   double n,m,a;
   cin>>n>>m>>a;
   cout<<(large) ceil(n/a)*(large)ceil(m/a)<<endl;
   return 0;
}
