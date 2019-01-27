#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

int main(){
    int l,h;
    while(scanf("%d %d", &h,&l)==2 && (h|l)){
        int ans = 0,last,curr;
        scanf("%d",&last);
        loop(i,1,l){
            scanf("%d",&curr);
            if(last < curr)ans+=curr-last;
            last = curr;
        }
        printf("%d\n",ans+(h-last));
    }
    return 0;
}

