#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a)
#define X first
#define Y second

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long large;

int ans[9][64];
int n,k;
vii st;

bool isValid(int i, int j){
  loop(k,0,st.size())
    if(abs(st[k].X-i) == abs(st[k].Y-j))
      return false;
  return true;
}

large backt(int d){
  printf("inte en (%d, %d)\n",d, k);
  if(k == 0)return 1;
  if(d >= n)return 0;
  large ans = 0;
  //printf("pongo en (%d, %d)\n",d, abs(d));
  loop(i,abs(d),n){
      if(isValid(i,i+d)){
        st.pb(ii(i,i+d));
        k--;
        printf("pongo en (%d, %d)\n",i,i+d);
        ans += backt(d+1);
        k++;
        st.pop_back();
      }
  }
  ans += backt(d+1);
  return ans;
}

int main(){
  for(n = 1;n<=1;n++){
    for(k=0;k<n*2;k++){
      printf("%d %d %lld\n",n,k,backt(1-n));
    }
  }
  return 0;
}
