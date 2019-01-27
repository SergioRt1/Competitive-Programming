#include <bits/stdc++.h>
#define loop(i,a,b) for(int i = a; i<b;i++)
#define pb(a) push_back(a)

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef unordered_map<int,int> ui;
typedef ui::const_iterator it;

int n;
char tab[25];
int cx,cy;
ui ans;
int ini = 403203039;

int dir[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};

int encode(){
    int code = 0;
    loop(i,0,25){
        if(tab[i] == ' '){
            code |= i<<25;
        }else{
            code |= (tab[i]-'0')<<i;
        }
    }
    return code;
}

int decode(int code){
    loop(i,0,25){
        if( ((code>>i)&1) == 0){
            tab[i] = '0';
        }else{
            tab[i] = '1';
        }
    }
    int b = code>>25&31;
    tab[b]=' ';
    cx = b/5;
    cy = b%5;
}

void print(){
    puts("<------");
    loop(i,0,5){
        loop(j,0,5)printf("%c",tab[i*5+j]);
        puts("");
    }
    puts("------>");
}

void sol(){
    vi cur,next;
    ans[ini] = 0;
    cur.pb(ini);
    loop(i,1,11){
        next.clear();
        loop(j,0,cur.size()){
            decode(cur[j]);
            loop(k,0,8){
                int x = cx+dir[k][0];
                int y = cy+dir[k][1];
                if(0 <= x && x < 5 && 0 <= y && y < 5){
                    int v;
                    tab[cx*5+cy] = tab[x*5+y];
                    tab[x*5+y] = ' ';
                    v = encode();
                    if(ans.find(v) == ans.end()){
                        next.pb(v);
                        ans[v] = i;
                    }
                    tab[x*5+y] = tab[cx*5+cy];
                    tab[cx*5+cy] = ' ';

                }
            }
        }
        cur = next;
    }
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%d",&n);
    string line;
    sol();
    getline(cin,line);
    loop(cas,0,n){
        loop(i,0,5){
            getline(cin,line);
            loop(j,0,5){
                tab[i*5+j] = line[j];
            }
        }
        it iter = ans.find(encode());
        if(iter == ans.end())puts("Unsolvable in less than 11 move(s).");
        else printf("Solvable in %d move(s).\n",iter->second);
    }
    return 0;
}
