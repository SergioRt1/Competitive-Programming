#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;
int mat[101][101];

int main(){
//   freopen("11221.in","r",stdin);
//   freopen("11221.out","w",stdout);
   int n;
   scanf("%d",&n);
   string line,fix;
   getline(cin,line);
   loop(cas,1,n+1){
      fix="";
      getline(cin,line);
      loop(i,0,line.length()){
         if(isalpha(line[i]))
            fix.append(1,tolower(line[i]));
      }
      int k = round(sqrt(fix.length()));
      bool ans = true;
      if(k*k!=fix.length())
         ans = false;
      else{
         int aux=0;
         loop(i,0,k)
            loop(j,0,k)mat[i][j]=fix[aux++];
      }
      loop(i,0,k&&ans)
         loop(j,0,k&&ans)
            if(mat[i][j]!=mat[j][i] || (mat[i][k-j-1] != mat[j][k-i-1]))
               ans = false;
      printf("Case #%d:\n",cas);
      if(ans)printf("%d\n",k);
      else puts("No magic :(");
   }
   return 0;
}
