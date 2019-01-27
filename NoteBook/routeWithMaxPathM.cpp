Rutas más cortas desde un nodo (costos enteros entre 1 y M) {O(V*M+E)}}
int[] dijkstraE(int[][] mAdy, int[][] lAdy, int v, int M) { // Apropiado para l<=M<=70
    int n=mAdy.length,b[][]=new int[M+1][n], tamB[]=new int[M+1], res[]=new int[n],d,i,j,t,q, sum=1;
    boolean vis[]=new boolean[n]; Arrays.fill(res, Integer.MAX_VALUE);
    for(res [v]=0,b[0][tamB[0]++]=v, d=0; sum>0; d++) {
        for (i=0, t=tamB[0]; i<t; i++) if (!vis (v=b[0][i]]) {
            vis [v]=true;
            for (int w:lAdy[v]) if (d+(q=mAdy[v][w])<res[w]){res[w]=d+q; b[q][tamB[q]++]=w;}
        }
        int arrTmp[]=b[0];
        for (j=1, sum=0; j<=M; j++){b[j-1]=b[j]; sum+=(tamB[j-1]=tamB[j]);}
        b[M]=arrTmp; tamB[M]=0;
    }
    return res;
}

