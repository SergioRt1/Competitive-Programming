#include <bits/stdc++.h>
#define loop(i,a,b) for(int i =a;i<b;i++)
#define X first
#define Y second

using namespace std;

typedef long long large;

bool prime[1000005];

void sieve(int ma){
    ma++;
    memset(prime,true,sizeof prime);
    prime[1]=prime[0]=false;
    for(large i=2;i<ma;i++)if(prime[i]){
        for(large j = i*i; j<ma ;j+=i){
            prime[j]=false;
        }
        //push_back prime(i)
    }
}

int main(){
    string line;
    sieve(100000);
    while(true){
        getline(cin,line);
        if(line == "0")break;
        int maxv = 1, len = line.length();
        loop(i,0,len)loop(j,1,6){
            int val = stoi(line.substr(i,j));
            //printf("(%d, %d) = %d\n",i,j,val);
            if(prime[val]){
                maxv = max(maxv,val);
            }
        }
        printf("%d\n",maxv);
    }
    return 0;
}
