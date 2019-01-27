#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)

using namespace std;

const int MAX_VAL = 2000005;
int segment[MAX_VAL*2];
int values[MAX_VAL];
int n;

int sfind(int i, int j, int low, int high, int root){
//    printf("%d %d\n",low,high);
    if(low == high)return segment[root];
    int mid = (low+high)>>1;
    if(low == i && high == j)return segment[root];
    int izq, der;
    if(i <= mid && mid < j){
        izq = sfind(i,mid,low,mid,(root<<1));
        der = sfind(mid+1,j,mid+1,high,root<<1|1);
        return izq+der;
    }
    else if(j <= mid){
        return sfind(i,j,low,mid,(root<<1));
    }else{
        return sfind(i,j,mid+1,high,root<<1|1);
    }

}

void sUpdate(int tar, int val, int low, int high, int root){
    if(tar == low && tar == high){
            segment[root] = val;
            return;
    }
    if(tar < low || high < tar)return;

    int mid = (low+high)>>1;
    sUpdate(tar,val,low,mid,root<<1);
    sUpdate(tar,val,mid+1,high,root<<1|1);
    segment[root] = segment[root<<1] + segment[root<<1|1];
}

void update(int tar, int val){
    values[tar] = val;
    sUpdate(tar,val,0,n-1,1);
}

void build(int i, int j,int root){
//    printf("%d %d %d\n",i,j,root);
    if(i == j){
//        printf("salgo en (%d %d) -> %d = %d\n",i,j,root,values[i]);
        segment[root] = values[i];
        return;
    }
    int mid = (i+j)>>1;
    build(i,mid,root<<1);
    build(mid+1,j,root<<1|1);
    segment[root] = segment[root<<1] + segment[root<<1|1];
//    printf("%d -> (%d %d) = %d\n",root,i,j,segment[root]);
}

int RMQ(int i, int j) {
    return sfind(i,j,0,n-1,1);
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    string op;
    memset(segment,-1,sizeof segment);
    int x,y,cas = 0;
    while(scanf("%d",&n) == 1 && n){
        if(cas != 0)puts("");
        loop(i,0,n)scanf("%d",&values[i]);
//        loop(i,0,n)printf("%d ",values[i]);

        printf("Case %d:\n",++cas);
        build(0,n-1,1);
//        loop(i,0,10)printf(" %d",segment[i]);
        while(cin>>op){
            if(op == "END")break;
            cin>>x>>y;
            if(op == "M"){
                printf("%d\n",RMQ(x-1,y-1));
            }else{
                update(x-1,y);
            }
        }
    }
    return 0;
}

