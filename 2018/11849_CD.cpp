#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)

using namespace std;

typedef unordered_set<int> ui;

int m,n;
ui cd;

int main(){
    while(scanf("%d %d",&n,&m)==2 && (n|m)){
        cd.clear();
        int tm;
        loop(i,0,n){
            scanf("%d",&tm);
            cd.insert(tm);
        }
        loop(i,0,m){
            scanf("%d",&tm);
            cd.insert(tm);
        }
        printf("%d\n",n+m-cd.size());
    }
    return 0;
}
