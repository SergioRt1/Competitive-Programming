#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
//   freopen("10361.in","r",stdin);
//   freopen("10361.out","w",stdout);
   int n;
   scanf("%d",&n);
   string l1,l2;
   getline(cin,l1);
   loop(i,0,n){
      getline(cin,l1);
      getline(cin,l2);
      int m1=-1,m2,a1=-1,a2;
      string s1,s2,s3,s4,s5;
      int m = l1.length();
      loop(i,0,m){
         if(l1[i]=='<'){
            if(m1==-1)m1=i;
            else m2 = i;
         }
         if(l1[i]=='>'){
            if(a1==-1)a1=i;
            else a2=i;
         }
      }
      s1 = l1.substr(0,m1);
      s2 = l1.substr(m1+1,a1-m1-1);
      s3 = l1.substr(a1+1,m2-a1-1);
      s4 = l1.substr(m2+1,a2-m2-1);
      s5 = l1.substr(a2+1);
      int p = l2.find("...");
      cout<<s1<<s2<<s3<<s4<<s5<<endl;
      cout<<l2.substr(0,p)<<s4<<s3<<s2<<s5<<endl;

   }
   return 0;
}
