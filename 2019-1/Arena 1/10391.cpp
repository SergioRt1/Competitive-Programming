#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

vector<string> dic;

int main(){
//   freopen("10391.in","r",stdin);
//   freopen("10391.out","w",stdout);
   string word;
   while(cin>>word){
      dic.push_back(word);
   }
   string s1,s2;
   sort(dic.begin(),dic.end());
   loop(i,0,dic.size()){
      loop(j,1,dic[i].length()-1){
         s1 = dic[i].substr(0,j);
         s2 = dic[i].substr(j);
         if(binary_search(dic.begin(),dic.end(),s1)&&binary_search(dic.begin(),dic.end(),s2)){
            cout<<s1<<s2<<endl;
            break;
         }
      }
   }
   return 0;
}

