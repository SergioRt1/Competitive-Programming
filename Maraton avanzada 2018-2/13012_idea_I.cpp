#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

int main(){
    int i,a,b,c,d,e;
    while(scanf("%d",&i)==1){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        printf("%d\n",( (i==a) +(i==b) +(i==c) +(i==d) +(i==e)));
    }
    return 0;
}
