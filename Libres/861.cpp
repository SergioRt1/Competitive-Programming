#include<bits/stdc++.h>
#define loop(i,a,b) for(int i = a;i<b;i++)
#define loopn(i,a,b) for(i = a;i<b;i++)
#define Y second
#define X first

using namespace std;

typedef long long large;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int n,k;
vii vec;

bool isValid(int i, int j){
    loop(k,0,vec.size())
        if(abs(vec[k].X - i) == abs(vec[k].Y - j) )return false;
    return true;
}


large backt(int d){
    if(k == 0) return 1;
    if(k >= n*2-1)return 0;
    if(d == n)return 0;
    int x,y;
    large ans = 0;
    loop(i,abs(d),n){
        x = i-abs(d);
        y = i;
        if(d > 0)swap(x,y);
        if(isValid(x,y)){
            vec.push_back(ii(x,y));
            k--;
            ans += backt(d+1);
            k++;
            vec.pop_back();
        }
    }
    ans += backt(d+1);
    return ans;
}

int main(){
    freopen("out.txt","w",stdout);
    printf("ans = [");
    loopn(n,1,9){
        printf("[");
        loopn(k,0,n*n-1){
            printf("%lld ,",backt(1-n));
        }
        printf("0], ");
    }
    printf("]");
    return 0;
}
