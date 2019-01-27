//fibonacci log(n)
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int f1[2][2]={{1,1},{1,0}};

//multiplication of square matrices O(n^3)
void matrixMultiplication(int a[2][2], int b[2][2]){//a=a*b
    int ans[2][2], len = 2,r;
    loop(i,0,len)loop(j,0,len){
        r=0;
        loop(k,0,len)r+=a[i][k]*b[k][j];
        ans[i][j]=r;
    }
    loop(i,0,len)loop(j,0,len)a[i][j] = ans[i][j];
}

//power matrix O(log(n))
void powerMatrix(int a[2][2],int n){//a^n
    if(n==0||n==1)return;
    powerMatrix(a,n>>1);
    matrixMultiplication(a,a);
    if(n&1)matrixMultiplication(a,f1);
}

//fibonacci O(log(n))
int fibonacci(int n){
    int fb[2][2]={{1,1},{1,0}};//fb^(n-1) = {{fn,fn-1},{fn-1,fn-2}}
    powerMatrix(fb,n-1);
    return fb[0][0];
}

int main(){
    int n;
    while(cin>>n){
        cout<<fibonacci(n)<<endl;
    }
    return 0;
}
