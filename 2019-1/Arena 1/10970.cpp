#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

int main(){
   int n1,n2;
   while(scanf("%d %d",&n1,&n2)==2){
      printf("%d\n",n1*n2-1);
   }
   return 0;
}
