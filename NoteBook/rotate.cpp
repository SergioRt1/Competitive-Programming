Rotar matriz a la derecha {0(n*m)}
long[][] rotarMatrizDer(long[][] mat) {
    int n=mat.length,m=n==0?0:mat [0).length; long res [][] =new long[m][n];
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) res[j][i]=mat[n-1-i][j];
    return res;
}
Rotar matriz a la izquierda {O(n*m) }
long[][] rotarMatrizizq(long[][] mat) {
    int n=mat.length, m=n==0?0:mat[0].length; long res[][]=new long[m][n];
    for(int i=0; i<n; i++)for(int j=0; j<m; j++) res[j][i]=mat[i][m-1-j];
    return res;
}
