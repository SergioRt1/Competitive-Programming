#include <bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++)
#define itloop(i,a) for(i = a.begin();i != a.end(); i++)
#define X first
#define Y second
#define pb(a) push_back(a)

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef viii::iterator it;

vi pset,tam, mst;
int nset,n, nod,arc;
viii graf;
it ite;

void init(int siz){
    int i;
    pset.clear();
    tam.clear();
    graf.clear();
    pset.resize(siz);
    tam.resize(siz);
    nset = siz;
    loop(i,0,siz){
        pset[i] = i;
        tam[i] = 1;
    }
}

int finds(int i){
    int pad = pset[i];
    return (pset[i]==i)? i: (pset[i] = finds(pset[i]));
}

bool unions(int i, int j){
    int x,y;
    x = finds(i);
    y = finds(j);
    if(x != y){
        if(tam[x]>tam[y]) swap(x,y);
        if(tam[x] == tam[y]) tam[y] +=1;
        pset[x] = y;
        nset--;
        return true;
    }
    return false;

}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    int u,v,c;
    loop(k,0,n){
        scanf("%d %d",&nod,&arc);
        init(nod);
        loop(i,0,arc){
            scanf("%d %d %d",&u,&v,&c);
            graf.pb(iii(c,ii(u-1,v-1)));
        }
        sort(graf.begin(),graf.end());
        int to = 0,mins = 1<<30,tm, vis;
        mst.clear();
        loop(i,0,graf.size()){
            if(unions(graf[i].Y.X, graf[i].Y.Y)){
               to += graf[i].X;
                mst.pb(i);
            }
        }
        loop(k,0,mst.size()){
            loop(i,0,nod){
                pset[i] = i;
                tam[i] = 1;
            }
            tm = 0;
            nset = nod;
            loop(i,0,graf.size()){
                vis = nset;
                if(i != mst[k] && unions(graf[i].Y.X, graf[i].Y.Y)){
                   tm += graf[i].X;
                }
                vis = nset;
            }
            if(nset == 1 && mins > tm) mins = tm;
        }
        printf("%d %d\n",to,mins);
    }
    return 0;
}
