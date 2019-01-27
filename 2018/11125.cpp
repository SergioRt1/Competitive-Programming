#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
using namespace std;

int n,icol,ilen;
int dp[65536];
int f(int bit){
    if(dp[bit] != -1)return dp[bit];
    int ans = 0,disp,bm;
    int veces = bit>>14&3;
    int col = bit>>12&3;
    loop(i,0,n)if(i != col){
        bm = bit;
        disp = bit>>(i*3)&7;
        bm ^= bm&12288;//limpia col
        bm |= i<<12;//set col
        int dis = min(3,disp)+1;
        loop(cant,1,dis)if(cant != veces){
            bm ^= bm&49152;//limpia veces
            bm ^= bm&(7<<(i*3)); //limpia disp (i)
            bm |= cant<<14;//set veces
            bm |= (disp-cant)<<(i*3);//set disp
            if( (bm&4095) == 0){//sin marbles
                if(icol != i && ilen != cant) ans += 1;
            }else ans += f(bm);
        }
    }
    return dp[bit] = ans;
}

int main(){
//    freopen("out.txt","w",stdout);
    int cs,tm,mask;
    scanf("%d",&cs);
    loop(tcas,0,cs){
        scanf("%d",&n);
        mask = 0;
        loop(i,0,n){
            scanf("%d",&tm);
            mask |= tm<<(i*3);
        }
        int disp,ans = 0,smask = mask;
        if( (mask&4095) == 0){//sin marbles
            ans += 1;
        }
        loop(i,0,n){
            mask = smask;
            mask ^= mask&12288;//limpia col
            mask |= i<<12;
            icol = i;
            disp = mask>>(i*3)&7;
            int dis = min(3,disp)+1;
            loop(cant,1,dis){
                memset(dp,-1,sizeof dp);
                mask ^= mask&(7<<(i*3)); //limpia disp (i)
                mask |= (disp-cant)<<(i*3);
                mask ^= mask&49152;//limpia veces
                mask |= cant<<14;
                ilen = cant;
                if( (mask&4095) == 0){//sin marbles
                    ans += 1;
                }else ans += f(mask);

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
