#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a)
using namespace std;
typedef vector<string> vi;
typedef vector<vi> vvi;

vvi juego;

int main(){
    freopen("in.txt","r",stdin);
    string s;
    while(cin>>s){
        if(s == "#")break;
        juego.clear();
        juego.pb(vi(1,s));
        loop(i,1,52){
            cin>>s;
            juego.pb(vi(1,s));
        }
        //loop(i,0,52)cout<<juego[i].back()<<endl;
        bool isAlive = true;
        while(isAlive){
            isAlive = false;
            loop(i,0,juego.size()){
                string s = juego[i].back();
                if(i >= 3 && (s[0] == juego[i-3].back()[0] || s[1] == juego[i-3].back()[1])){
                    //puts("in -3");
                    juego[i].pop_back();
                    juego[i-3].pb(s);
                    isAlive = true;
                    if(juego[i].empty()){
                        juego.erase(juego.begin()+i);
                    }
                    break;
                }else if(i >= 1 && (s[0] == juego[i-1].back()[0] || s[1] == juego[i-1].back()[1])){
                    //puts("in -1");
                    juego[i].pop_back();
                    juego[i-1].pb(s);
                    isAlive = true;
                    if(juego[i].empty()){
                        juego.erase(juego.begin()+i);
                    }
                    break;
                    //puts("out -1");
                }

            }
        }
        printf("%d pile",juego.size());
        if(juego.size()>1)putchar('s');
        printf(" remaining :");
        loop(i,0,juego.size())cout<<" "<<juego[i].size();
        putchar('\n');

    }
    return 0;
}
