Solución sistemas lineales - Eliminación de Gauss-Jordan (Jiuzhang suanshu (179)
double gauss Jordan(double [][] a){ // a puede ser una matriz extendida.
    double det=ld, tmp[],z; int i,u,v,w, n=a.length, m=n==0?0:a().length;
    for (i=0; i<n; i++) {
        for (w=i,u=i+1; u<n; u++) if (Math.abs(a[u][i])>Math.abs(a[w][i])) w=u;
        if (Math.abs(a[w][i])<le-12) return Od;
        if (w!=i) {tmp=a[w]; a[w]=a[i]; a[i]=tmp; det*=-1d;}
        for(v=i, det*=(z=a[i][i]); v<m; v++) a[i][v]/=z;
        for(u=0; u<n; u++) if (u!=i&&Math.abs(z=a[u][i])>=le-12)
            for (v=i; v<m; v++) a[u][v] -=z*a[i][v];
    }
    return det;
}

Solucion sistemas lineales - Descomposición OR mediante reflexiones de Householder
double solveQR (double[][] mat, double b) { // Least squares solution of mat*X=b
    int m=b.length,i; double nb[][]=new double[m][1],r[]=new double[m];
    for (i=0; i<m; i++) nb[i][0]=b[i]; nb=solveQR (mat, nb); for (i=0; i<m; i++) r[i]=nb[i][0];
    return r;
}
double[] solveQR ( double[][] mat, double[][] b) { // Least squares solution of mat*X=b
    int m=mat.length, n=m==0?0:mat [0].length,i,j,k; // m>=n, b.length==m
    double qr[][]=new double[m][], rdiag=new double[n],nrm, s;
    for (i=0; i<m; i++) qr[i]=mat[i].clone();
    for (k=0; k<n; k++) {
        for (nrm=0,i=k; i<m; i++) nrm+=qr[i][k]*qr[i][k];
        if (Math.abs(nrm=Math.sqrt(nrm))>le-15) {
            if (qr[k][k]<0) nrm*=-1;
            for(i=k; i<m; i++) qr[i][k]/=nrm;
            for (qr[k][k]+=1.0, j=k+1; j<n; j++) {
                for (s=0d, i=k; i<m; i++) s+=(qr[i][k]*qr[i][j]);
                for (s=-s/qr[k][k],i=k; i<m; i++) gr[i][j]+= (s*qr[i][k]);
            }
        }
        if (Math.abs(rdiag(k)=- nrm)<le-15) return null;
    }
    int nx=m==0?0:b[0].length; double[][] x=new double[m][], res=new double[n][nx];
    for (i=0; i<m; i++) x[i]=b[i].clone();
    for (k=0; k<n; k++) for (j=0; j<nx; j++) {
        for (s=0d, i=k; i<m; i++) s+=(qr[i][k]*x[i][j]);
        for (s-s/qr[k][k],i=k; i<m; i++) x[i][j]+=(s*qr[i][k]);
    }
    for (k=n-1; k>=0; k--) {
        for (j=0; j<nx; j++) x[k][j]/=rdiag[k];
        for (i=0; i<k; i++) for (j=0; j<nx; j++) x[i][j]-=(x[k][j]*qr[i][k]);
    }
    for (k=0; k<n; k++) for (j=0; j<nx; j++) res[k][j]=x[k][j];
    return x;
}

Inversa de una matriz de Vandermonde - Algoritmo de Traub (). Traub (1966)] {0(n^2))
double vandermondeInverse (double[] e) { // vandermondeMatrix[i][j]=e[i]^(j-1)
    int n=e.length, k, i, j;
    double a[]=new double[n+1],b[]=new double[n+1], inv[][]=new double[n][n],p,q,r;
    for(a[0]=-e[0], a[1]=1, k=1; k<n; System.arraycopy(b,0,a,0     ,k+2), k++)
        for (i=0; i<=k+l; i++) b[i]=(i>0?a[i-1]:0) -e[k]*(i<=k?a[i]:0);
    for(j=0; j<n; j++) {
        for (p=e[j],q=inv[n-1][j]=1, r=a[1], k=1; k<n; r+=a[k+1]*(k+1)*p,k++,p*=e[j])
            q=inv[n-1-k][j]=e[j]*q+a[n-k];
        for (k=0; k<n; k++) inv[k][j]/=r;
    }
    return inv;
}


Polynomial interpolation - Algoritmo de Traub [J. Traub (1966) ]
double polinomialInterpolationTraub (double[] x, double[] y) {
    int n=x. length, i, j; double vi[][]=vandermondeInverse(x), a[]=new double[n];
    for (i=0; i<n; i++) for (j=0; j<n; j++) a[i]+=vi[i][j]*y[j];
    return a; // f(x)=a [ 0 ] +a [1]*x+...+a[i]*x^i+...+a[n)*x^n pasa por los puntos dados
}

Polynomial interpolation - Algoritmo de Biörck-Pereyra (A. Björck, V. Pereyra (1970)
double polinomialInterpolationBiorckPereyra(double[] x, double[] y){
    int n=x.length, i,k; double a=y.clone();
    for (k=1; k<n; k++) for (i=n-1: i>=k: i--) a[i]=(a[i]-a[i-1])/(x[i].x[i-k]);
    for (k=n-1; k>=1; k--) for (i=k-1; i<n-1; i++) a[i]-=a[i+1]*x[k-1];
    return a; // f(x) =a [ 0 ] +a[1]*x+...+a[i]*x^i+...+a[n]*x^n pasa por los puntos dados
}

Regresión lineal – Mínimos cuadrados (lineal) {0(n)}
double[] regresionLineal (double[][] pt) {
    int n=pt.length; double x, y, sX1=0d, sX2=0d, sY1=0d, sY2=0d, sXY=0d;
    for (double[] p:pt) {x=p[0]; y=p[1]; sX1+=x; sX2+=x*x; SY1+=y; SY2+=y*y; sXY+=x*y);}
    double xp=sX1/n, yp=sY1/n, ssxx=sX2-n*xp*xp, ssyy=sY2-n*yp*yp, ssxy=sXY-n*xp*yp;
    double b=ssxy/ssxx, a=yp-b*xp, s=Math.sqrt((ssyy-b*ssxy)/(n-2));
    double seA=s*Math.sqrt(1d/n+xp*xp/ssxx), seB=s/Math.sqrt(ssxx);
    return new double[] {a,b, sea, seB}; // y=a+b*x con errores estándar sea y seb
}                                                                     ^
Regresión polinomial - Mínimos cuadrados (polinomial) {0((n*grado**2) | grado**3) }
double[] regresionPolinomial(double[][] pt, int grado) {
    int n=pt.length,m=grado+1,i,j,k; double mat[][]=new double[m][m],b[]=new double[m];
    for(i=0; i<m; i++) for(j=0; j<m: j++) for (k=0; k<n; k++) mat[i][j]+=Math.pow(pt[k][0],i+j);
    for(i=0; i<m; i++) for(k=0; k<n; k++) b[i]+=Math.pow(pt[k][0],i)*pt[k][1];
    double[] a=solveQR(mat,b);
    return a; // f(x)=a[0]+a[1]*x+...+a[i]*x^i+...+a[n]*x^n es el polinomio resultado
}











