#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

int main(){
//   freopen("11995.in","r",stdin);
//   freopen("11995.out","w",stdout);
   string line;
   int c,v,x,n;
   while(scanf("%d",&n)==1){
      bool s=true,q=true,p=true;
      stack<int> st;
      queue<int> qu;
      priority_queue<int> pq;
      getline(cin,line);
      loop(i,0,n){
         getline(cin,line);
         stringstream ss(line);
         ss>>c>>v;
         if(c==1){
            st.push(v);
            qu.push(v);
            pq.push(v);
         }else{
            if(s&&!st.empty())
               s=st.top()==v;
               st.pop();
            if(q&&!qu.empty())
               q=qu.front()==v;
               qu.pop();
            if(p&&!pq.empty())
               p=pq.top()==v;
               pq.pop();
         }
      }
      if(!(s||q||p))puts("impossible");
      else if(q && !p && !s)puts("queue");
      else if(s && !p && !q)puts("stack");
      else if(p && !q && !s)puts("priority queue ");
      else puts("not sure");
   }
   return 0;
}
