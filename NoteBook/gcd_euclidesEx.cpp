Máximo común divisor - Algoritmo de Euclides (Euclides (300AC)] {0(log(arb))}
long gcd(long a, long b) {long t; while (b!=0) {t=b; b=a%b; a=t;} return a;}
Máximo común divisor precalculado {O(MP)}
int[][] gcd(int M) { // [O..M][0..M]
    int r[][]=new int [M+1][M+1],i,j;
    for (i=0; i<=M; i++) for (j=0; j<=M; j++) r[i][j]=i==0?j :(j==0?i:(i>j?r[i%j][j]:r[j%i][i]));
    return r;
}
Máximo común divisor - Algoritmo extendido de Euclides [Euclides (300AC)] {O(logz(arb))}
long[] gcdExtendido (long a, long b) { // answer [0]=gcd(a,b), answer[1]*a+answer [2]*b=gcd(a,b)
    boolean bs=a<b; long xAnt=1, yAnt=0, x=0, y=1;
    if (bs) {long tmp=a; a=b; b=tmp; }
    while (b!=0) {
        long q=a/b, r=a%b, xTmp=xAnt-q*x,yTmp=yAnt-q*y; a=b; b=r; xAnt=x; yAnt=y; x=xTmp; y=yTmp;
    }
    return new long[]{a,bs?yAnt: xAnt, bs?xAnt:yAnt};
}
Mínimo común múltiplo {0(log(arb))}
long lcm(long a, long b) {return a*(b/gcd(a,b));}
Primos relativos (coprimos) {O(log (arb))}
boolean primosRelativos (long a, long b) {return gcd(a,b)==1L;}

Aproximación de Stirling - [Abraham de Moivre, James Stirling]
n! =-=raiz(2PIn)(n/e)^n
Teorema pequeño de Fermat a^(p-l)=1 (mod p) donde p es primo y a no es múltiplo de p


