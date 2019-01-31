#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

vector<string> key;
vector<string> basura;
unordered_map<string,int> exc;

int main(){
//   freopen("409.in","r",stdin);
//   freopen("409.out","w",stdout);
   string tmpo, line,fix,str;
   int cas = 0,n,m;
   while(scanf("%d %d",&n,&m)==2){
      key.clear();
      loop(i,0,n){
         cin>>tmpo;
         key.push_back(tmpo);
      }
      sort(key.begin(),key.end());
      getline(cin,line);
      exc.clear();
      basura.clear();
      int ma = 0, cont;
      loop(i,0,m){
         cont = 0;
         fix.clear();
         getline(cin,line);
         loop(k,0,line.length())
            fix.append(1,isalpha(line[k])?tolower(line[k]):' ');
         stringstream ss(fix);
         while(ss>>str)
            if(binary_search(key.begin(),key.end(),str))cont++;
         exc[line]=cont;
         basura.push_back(line);
         ma = max(ma,cont);
      }
      printf("Excuse Set #%d\n",++cas);
      loop(i,0,m){
         if(exc[basura[i]]==ma)cout<<basura[i]<<endl;
      }
   puts("");
   }
   return 0;
}
