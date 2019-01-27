#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
using namespace std;

int n;
int dp[1048576];
int f(int bit){
    if(dp[bit] != -1)return dp[bit];
    int ans = 0,bm;
    int c0i = bit>>12&3;
    int s0i = bit>>14&3;
    int cfi = bit>>16&3;
    int sfi = bit>>18&3;
    int C[4] = {bit&7,(bit>>3)&7,(bit>>6)&7,(bit>>9)&7};
    bm = bit;
    bm ^= bm&(7<<(3*c0i));
    bm |= (C[c0i]-s0i)<<(3*c0i);
    bm ^= bm&(7<<(3*cfi));
    bm |= (C[cfi]-sfi)<<(3*cfi);
    if( (bm&4095) == 0 && s0i != sfi && c0i != cfi){//sin marbles
        return dp[bit] = 1;
    }
    C[c0i] -= s0i;
    C[cfi] -= sfi;
    loop(c0,0,n)if(c0 != c0i){
        bm ^= bm&(3<<12);
        bm |= c0<<12;
        loop(s0,1,4)if(s0 != s0i && C[c0] >= s0){
            bm ^= bm&(3<<14);
            bm |= s0<<14;
            loop(cf,0,n)if(cf != cfi){
                bm ^= bm&(3<<16);
                bm |= cf<<16;
                loop(sf,1,4)if( sf != sfi && ( (c0==cf && C[cf]>=sf+s0)||(c0!=cf && C[cf]>=sf) ) ){
                    bm ^= bm&(3<<18);
                    bm |= sf<<18;
                    ans+= f(bm);
                }
            }
        }
    }
    return dp[bit] = ans;
}

int main(){
//    freopen("out.txt","w",stdout);
    int cs,mask,C[4];
    memset(dp,-1,sizeof dp);
    scanf("%d",&cs);
    loop(tcas,0,cs){
        memset(C,0,sizeof C);
        scanf("%d",&n);
        mask = 0;
        loop(i,0,n){
            scanf("%d",&C[i]);
            mask |= C[i]<<(i*3);
        }
        int ans = 0;
        if( (mask&4095) == 0){//sin marbles
            ans += 1;
        }
        loop(c0,0,n){
            mask ^= mask&(3<<12);
            mask |= c0<<12;
            loop(s0,1,4)if(C[c0]>=s0){
                mask ^= mask&(3<<14);
                mask |= s0<<14;
                loop(cf,0,n)if(cf != c0){
                    mask ^= mask&(3<<16);
                    mask |= cf<<16;
                    loop(sf,1,4)if(sf != s0 && C[cf]>=sf){
                        mask ^= mask&(3<<18);
                        mask |= sf<<18;
                        ans += f(mask);
                    }
                }

            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
