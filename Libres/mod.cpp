#include <bits/stdc++.h>
#define loop(i,a,b) for(int i= a;i<b;i++)

using namespace std;
int main(){
    int n = 100;
    loop(k,0,n){
        printf("%d %d\n",k,(n-k-1)%(n+1));
    }
    return 0;
}
