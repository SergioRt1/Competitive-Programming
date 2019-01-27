#include <bits/stdc++.h>
using namespace std;
//Sergio Andres Rodriguez Torres
//Veredicto: Accepted
int v[3];
int main(){
    ios_base::sync_with_stdio(false);
    string a;
    long long ans;
    while(cin>>a){
        int c = 0;
        v[1] = v[2] = 0;
        v[0] = 1;
        ans = 0;
        for(int i = 0; i < a.length(); i++){
            if(!isdigit(a[i])){
                c = 0;
                v[1] = v[2] = 0;
                v[0] = 1;
                continue;
            }
            c = (c+a[i]-'0')%3;
            ans += v[c];
            v[c]++;
        }
        cout<<ans<<endl;
    }
}
