#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)

using namespace std;

typedef unordered_map<int,int> um;
typedef deque<int> di;
typedef deque<di> ddi;

int t;
um grup;
ddi fila;



int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int l;
    int cas = 0;
    while(scanf("%d",&t)==1 && (t) ){
        grup.clear();
        fila.clear();
        loop(i,0,t){
            scanf("%d",&l);
            int val;
            loop(j,0,l){
                scanf("%d",&val);
                grup[val] = i;
            }
        }
        string op;
        int val;
        printf("Scenario #%d\n",++cas);
        while(cin>>op){
            if(op=="STOP"){
                break;
            }else if(op == "ENQUEUE"){
                scanf("%d",&val);
                bool cont = false;
                loop(i,0,fila.size()){
                    if(grup[fila[i].front()] == grup[val]){
                        fila[i].push_back(val);
                        cont = true;
                        break;
                    }
                }
                if(cont)continue;
                di nuevoGrupo;
                nuevoGrupo.push_back(val);
                fila.push_back(nuevoGrupo);
            }
            else if(op=="DEQUEUE"){
                scanf("%d",&val);
                printf("%d\n",fila.front().front());
                fila.front().pop_front();
                if(fila[0].empty()){
                    fila.pop_front();
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
