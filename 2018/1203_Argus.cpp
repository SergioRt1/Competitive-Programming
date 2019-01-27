#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;

class cmp{
    public : bool operator()(const ii a, const ii b)const{
    return a.X > b.X || (a.X == b.X && a.Y > b.Y);
    }
};

unordered_map<int, int> inicial;
priority_queue<ii,vector<ii>,cmp> pq;

int main(){
//    freopen("out.txt","w",stdout);
    string op;
    int val, time,n;
    while(cin>>op){
        if(op == "#")break;
        scanf("%d %d",&val,&time);
        pq.push(ii(time,val));
        inicial[val] = time;
//        printf("in %d %d\n",pq.top().Y,pq.top().X);
    }
    scanf("%d", &n);
    loop(i,0,n){
        ii tp = pq.top();
        pq.pop();
        printf("%d\n",tp.Y);
        pq.push(ii(tp.X+inicial[tp.Y],tp.Y));
    }
    return 0;
}
