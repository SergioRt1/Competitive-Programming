#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

int l,n;

int main(){
    int cas;
    scanf("%d",&cas);
    loop(ca,0,cas){
        if(ca != 0)puts("");
        scanf("%d %d",&l,&n);
        loop(i,0,1<<l){
            bitset<16> bit(i);
            if(bit.count() == n){
                string s = bit.to_string();
                cout<<s.substr(16-l,16)<<endl;
            }
        }
    }
    return 0;
}

