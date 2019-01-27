#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define X first
#define Y second
using namespace std;

typedef unsigned long long lar;
typedef deque<lar> dl;
typedef pair<lar,char> pl;
typedef unordered_map<lar,pl > maplar;

maplar::iterator it_tb;
maplar::iterator it_tn;
maplar::iterator it_sb;
maplar::iterator it_sn;

int n;

lar tar = 1147797409030816545;
maplar pads,padt;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

char toS[4]={'U','L','R','D'};
char toSi[4]={'D','R','L','U'};

string f(lar bit){
    int sou[4][4];
    int inCero,x,y;
    lar nbit,vis = 0;
    deque<lar> Q;
    Q.push_back(bit);
    Q.push_back(tar);
    pads[bit] = pl(bit,0);
    padt[tar] = pl(tar,0);
    while(!Q.empty()){
        bit = Q.front();
        vis++;
        if(vis%10000 == 0)printf("%llu size: (%d, %d) => cap: %d\n",vis,pads.size(),padt.size(),padt.max_size());
        Q.pop_front();
        loop(i,0,16){
            if( (sou[i>>2][i&3]=bit>>(i*4)&15) == 0){
                inCero = i;
            }
        }
        loop(i,0,4){
            x = (inCero>>2)+dx[i];
            y = (inCero&3)+dy[i];
            if(0 <= x && x < 4 && 0 <= y && y < 4){
                nbit = bit;
                nbit |= (lar)(sou[x][y])<<(inCero<<2);
                nbit ^= nbit&((lar)15 <<( ((x<<2)+y)<<2  ));
                it_sb = pads.find(bit);
                it_sn = pads.find(nbit);
                it_tb = padt.find(bit);
                it_tn = padt.find(nbit);
                if(it_sn == pads.end() && it_tn == padt.end()){
                    if( it_sb != pads.end()){
                        pads[nbit] = pl(bit,i);
                    }else if(it_tb != padt.end()){
                        padt[nbit] = pl(bit,i);
                    }
                    Q.push_back(nbit);
                }else if(it_sb != pads.end() && it_tn != padt.end()){
                    string ss = "";
                    ss = ss+toS[i];

                    while( ((it_tn = padt.find(nbit))->Y).X != nbit ){
                        ss = ss+toSi[(it_tn->Y).Y];
                        nbit = (it_tn->Y).X;
                    }
                    while( ((it_sb = pads.find(bit))->Y).X != bit ){
                        ss = toS[(it_sb->Y).Y]+ss;
                        bit = (it_sb->Y).X;
                    }

                    return ss;
                }else if(it_tb != padt.end() && it_sn != pads.end()){
                    string ss = "";
                    ss = ss+toSi[i];
                    while( ((it_tb = padt.find(bit))->Y).X != bit ){
                        ss = ss+toSi[(it_tb->Y).Y];
                        bit = (it_tb->Y).X;
                    }
                    while( ((it_sn = pads.find(nbit))->Y).X != nbit ){
                        ss = toS[(it_sn->Y).Y]+ss;
                        nbit = (it_sn->Y).X;
                    }
                    return ss;
                }

            }
        }
    }
    return "This puzzle is not solvable.";
}

int main(){
    freopen("in.txt","r",stdin);
    lar tm;
    while(scanf("%d",&n) == 1){
        loop(cas,0,n){
            lar bit = 0;
            pads.clear();
            padt.clear();
            loop(i,0,16){
                scanf("%llu",&tm);
                bit |= tm<<(4*i);
            }
            cout<<f(bit)<<endl;
        }
    }
    return 0;
}
