Ciclo Hamiltoniano (O(E^v) )
int[] hamilton(int[][] lAdy) {
    int n=lAdy.length, cam[]=new int[n+1]; if (!hamilton (lAdy, new boolean[n], cam,0,0)) return null;
    return cam;
}
boolean hamilton (int[][] lAdy, boolean[] vis, int[] cam, int t, int v) {
    if (vis[v]&&t<cam.length-1) return false; cam[t++]=v; if (t==cam.length) return v==cam[0];
    vis[v]=true; for (int w: lAdy[v]) if(hamilton(lAdy, vis, cam, t,w)) return true;
    vis[v]=false; return false;
}

