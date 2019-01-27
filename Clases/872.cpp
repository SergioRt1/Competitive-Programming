#include<bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n,cs;
string linea;
int graf[26][26];
char nodo;
int nodos[26],ans[26];
int nm;
bool us[26];

void tsort(int u){
    if(u==n){
        nm+=1;
        printf("%c",ans[0]+'A');
        loop(k,1,n) printf(" %c",ans[k]+'A');
        puts("");
    }else{
        loop(i,0,n){
            if(!us[nodos[i]]){
                bool valid=true;
                loop(j,0,u) if(graf[nodos[i]][ans[j]])valid=false;
                if(valid){
                    ans[u]=nodos[i];
                    us[nodos[i]]=true;
                    tsort(u+1);
                    us[nodos[i]]=false;
                }
            }
        }
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&cs);
    getline(cin,linea);
    loop(cas,0,cs){
        getline(cin,linea);
        getline(cin,linea);
        stringstream ss;
        ss<<linea;
        n=0;
        while(ss>>nodo) nodos[n++] = nodo-'A';
        sort(nodos,nodos+n);
        getline(cin, linea);
        memset(graf,0,sizeof graf);
        memset(us,false,sizeof us);
        ss.clear();
        ss<<linea;
        while(ss>>linea) graf[linea[0]-'A'][linea[2]-'A']=1;
        nm = 0;
        tsort(0);
        if(nm==0)puts("NO");
        if(cas!=cs-1) puts("");
    }
    return 0;
}
