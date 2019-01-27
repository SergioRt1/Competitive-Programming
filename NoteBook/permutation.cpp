k-ésima permutación en orden lexicográfico {0(n?)}
char[] permutation(int k, char[] s) {
    int n=s.length, fact=1,i,j,tj; char ts; s=s.clone();
    for(j=2; j<n; j++) fact*=j;
    for(j=1; j<n; j++) {
        tj=(k/fact)%(n+1-j); ts=s[j+tj-1); for (i=j+tj; i>j; i--) s[i-1]=s(1-2);
        s[j-1]=ts; fact/=n-j;}
    return s;}


