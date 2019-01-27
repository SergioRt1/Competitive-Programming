#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
#define itloop(i,a) for(i = a.begin();i != a.end();i++)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef pair<double,ii> dii;
typedef vector<dii> vdii;

const int lim = 780;
const int inf = 1<<30;

int n,k;
ii f,h;
vector<int> pset,tam;
int nSet;
vdii graf;
int xv[lim], yv[lim];
vdii::iterator it;

void initSet(int _size){
    int i;
    pset.resize(_size);
    tam.resize(_size);
    nSet = _size;
    loop(i,0,_size){
        pset[i] = i;
        tam[i] = 1;
    }
}

int findS(int i){
    return (pset[i]==i)?i:(pset[i]=findS(pset[i]));
}

void unionS(int i, int j){
    int x,y;
    x = findS(i);
    y = findS(j);
    if(x==y)return;
    pset[x]=y;
    tam[y]+=tam[x];
    nSet--;
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    loop(ca,0,cas){
        int x,y;
        scanf("%d %d",&k,&n);
        initSet(n);
        graf.clear();
        loop(i,0,n){
            scanf("%d %d",&xv[i],&yv[i]);
        }
        loop(i,0,n){
            loop(j,0,n)if(i != j)graf.push_back(dii(sqrt( (xv[i]-xv[j])*(xv[i]-xv[j])+ (yv[i]-yv[j])*(yv[i]-yv[j]) ),ii(i,j)));
        }
        sort(graf.begin(),graf.end());
        double ans = 0;
        itloop(it,graf){
            if(findS(it->Y.X) != findS(it->Y.Y)){
                if(k--<=0)ans = it->X;
                unionS(it->Y.X, it->Y.Y);
            }
        }
        printf("%.2lf\n",ans);

    }
    return 0;
}
