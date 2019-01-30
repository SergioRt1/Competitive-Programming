#include<bits/stdc++.h>
#define loop(i,a,b) for(auto i=a;i<b;i++)
#define loopit(i,a) for(auto i=a.begin();i!=a.end();i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

stack<int> st;
queue<int> qu;
priority_queue<int> pq;

int main(){
   freopen("11995.in","r",stdin);
   freopen("11995.out","w",stdout);
   string line;
   int c,v,x,n;
   while(scanf("%d",&n)==1){
      bool s=true,q=true,p=true;
      while(!st.empty())st.pop();
      while(!qu.empty())qu.pop();
      while(!pq.empty())pq.pop();
      getline(cin,line);
      loop(i,0,n){
         scanf("%d %d",&c,&v);
         if(c==1){
            if(s)st.push(v);
            if(q)qu.push(v);
            if(p)pq.push(v);
         }else{
            if(s)
               if(st.empty() || st.top() != v)
                  s=false;
               else st.pop();
            if(q)
               if(qu.empty() || qu.front() != v)
                  q=false;
               else qu.pop();

            if(p)
               if(pq.empty() || pq.top()!=v)
                  p=false;
               else pq.pop();
         }
      }
      if(!(s||q||p))puts("impossible");
      else if(q && !p && !s)puts("queue");
      else if(s && !p && !q)puts("stack");
      else if(p && !q && !s)puts("priority queue");
      else puts("not sure");
   }
   return 0;
}
