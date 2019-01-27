Binary Search {log (n)}
int busquedaBinaria (long[] a, int lI, int lS, long v) {
while(lI<=lS){int IM=(lI+lS)/2; long p=a[lM]; if (p<v) lI=lM+1; else if (p>v) lS=lM-1; else return lM;} return - (lI+1);
