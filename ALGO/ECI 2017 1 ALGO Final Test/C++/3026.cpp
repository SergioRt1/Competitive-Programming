#include<bits/stdc++.h>
#define loop(i,a,b) for(i = a; i < b;i++)
using namespace std;
//Sergio Andres Rodriguez Torres
//Veredicto: Accepted
int n;
string s;
int p[1000001];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int cas = 0,i,pa;
    while(true){
        cas++;
        cin >> n;
        if(!n) break;
        cin >> s;
        cout<<"Test case #"<<cas<<endl;
        int a = 0,k = 0,q = 0;
        p[0] = p[1] = 0;
        loop(q,1,n){
            while(k && s[k] != s[q]) k = p[k-1];
            if(s[k] == s[q]) k++;
            p[q] = k;
        }
        a = 0;
        loop(i,2,n+1){
            if(p[i-1] && !(i%(i-p[i-1]))) cout<<i<<" "<<i/(i-p[i-1])<<endl;;
        }
        cout<<endl;
    }
    return 0;
}
