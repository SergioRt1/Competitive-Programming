Rutas más cortas con caminos de longitud menor o igual que q {O(V**3*log2 (q))}
void mmult(double[][] a, double b, double [][] tmp) { // a*=b
    int n=a.length;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        double r=Double.POSITIVE INFINITY;
        for (int k=0; k<n; k++) if (a[i][k]<r&&b[k][j]<r) r=Math.min(r,a[i][k]+b[k][j]);
        tmp[i][j]=r;
    }
    for (int i=0; i<n; i++) System.arraycopy (tmp[i],0, a[i],0,n);
}
double[][] costoCaminosQ (double[][] mAdy, int q) {
    int n=mAdy.length, y=q; double[][] x=new double[n][n], z=new double[n][n],u=new double[n][n];
    for (int i=0; i<n; i++){
            Arrays.fill(z[i],Double.POSITIVE INFINITY); System.arraycopy(mAdy[i],0,x[i],0,n); z[i][i]=0;}
    while(y!=0) {if ((y&1)==0) {y/=2; mmult(x,x,u);} else {y-- ; mmult(z, x, u);}}
    return z;
}
