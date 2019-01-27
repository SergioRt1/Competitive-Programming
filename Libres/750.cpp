#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
#define X first
#define Y second
#define ms(a,b) memset(a,b,sizeof a)
#define pb(a) push_back(a)
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef set<vi> si;
int Cdisp[8];
int in,ja;
si ans;

bool movimientoValido(int i, int j){
    if(Cdisp[j] != -1)return false;
    int k;
    loop(k,0,8)
        if(Cdisp[k] != -1 && (Cdisp[k]==i || Cdisp[k]-k == i-j || Cdisp[k]+k == i+j))return false;
    return true;
}

bool backTracking(int i){
    bool posible = false;
    int j;
    if(i == 8){
        vi tm;
        loop(j,0,8)tm.pb(Cdisp[j]+1);
        ans.insert(tm);
        return true;
    }
    if(i == in){
        posible = backTracking(i+1);
    }else loop(j,0,8){
                if(movimientoValido(i,j)){
                    Cdisp[j] = i;
                    posible |= backTracking(i+1);
                    if(i!=in&&j!=ja){
                        Cdisp[j] = -1;
                    }
                }
            }
    return posible;
}

int main(){
    //freopen("o.txt","w",stdout);
    int a,k,i;
    scanf("%d",&a);
    loop(k,0,a){
        ans.clear();
        ms(Cdisp,-1);
        scanf("%d %d",&in,&ja);
        in--;ja--;
        Cdisp[ja] = in;
        backTracking(0);
        puts("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n");
        i = 1;
        for(set<vi>::iterator it = ans.begin(); it != ans.end(); it++){
            printf("%2d      %d %d %d %d %d %d %d %d\n",i++,(*it)[0],(*it)[1],(*it)[2],(*it)[3],(*it)[4],(*it)[5],(*it)[6],(*it)[7]);
        }
        if(k!=a-1)puts("");
    }
    return 0;
}
