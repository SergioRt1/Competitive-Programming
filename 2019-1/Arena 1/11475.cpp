#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a,b) for(auto i=a;i!=b;i++)
#define X first
#define Y second

typedef long long large;

using namespace std;

string P,T;
int b[100005];
int m,n;

void kmppre(){
   int j = -1;
   loop(i,0,m){
      if(j>=0 && P[i]==P[j]) b[i]=b[j]+1;
      else b[i]=j;
      while(j>=0 && P[i]!=P[j]) j=b[j];
      j++;
   }
}

int kmp(){
   int j=0;
   loop(i,0,n){
      while(j >=0&&T[i]!=P[j]) j=b[j];
      j++;
   }
   return j;
}

int main(){
//   freopen("in.in","r",stdin);
//   freopen("out.out","w",stdout);
   while(getline(cin,P)){
      memset(b,0,sizeof b);
      m = n = P.length();
      T=P;
      reverse(P.begin(),P.end());
      kmppre();
      int ind = kmp();
      cout<<T<<P.substr(ind)<<endl;
   }
   return 0;
}
