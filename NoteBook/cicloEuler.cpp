Ciclo/Camino Euleriano partiendo de un nodo (grafos dirigidos) {O(V+E) }
int[] euler(int[][] lAdy, int v) { // Lo encuentra si existe
    List<Integer> r=new ArrayList<Integer>(); euler (lAdy, new int [lAdy.length],v,r);
    int t=r.size(), a[]=new int[t],i; for (i=0; i<t; i++) a[i]=r.get(t-1-i); return a;
}
void euler(int[][] lAdy, int[] tams, int v, List<Integer> r) {
    while (tams [v]<lAdy[v].length) euler(lAdy, tams, lAdy[v][tams [v]++],r); r.add(v); }

Existencia de un ciclo/camino Euleriano (grafos no dirigidos) {O(V+E) } Un grafo no dirigido G=(V, E) tiene un ciclo Euleriano si es conexo y todo vértice v tiene grado par.
Un grafo no dirigido G=(V, E) tiene un camino Euleriano si es conexo y todo vértice v tiene grado par, excepto dos vértices que tienen grado impar.

Ciclo/Camino Euleriano partiendo de un nodo (grafos no dirigidos) {O(V+E) }
int[] euterND (int[][] lAdy, int v) { // Lo encuentra si existe
    int n=lady.length; Lists<Integer> r=new ArrayList<Integer>();
    eulerND(lAdy, new int[n], new boolean[n][n],v,r);
    int t=r.size()), a[]=new int[t],i; for (i=0; i<t; i++) a[i]=r.get(t-1-i); return a;
}

void eulerND (int[][] lAdy, int[] tams, boolean[][] vis, int v, List<Integer> r) {
    for (int x; tams[v]<lAdy[v].length; if (!vis[v][x= lAdy[v][tams[v]++] ]){
        vis [v][x]=vis[x][v]=true; eulerND (lAdy, tams, vis,x,r);}
        r.add(v);
}
