large gray (large n) {return n^(n>>1);}
large inverseGray (large n) {
for (large ish=1, ans=n, idiv; true; ish<<=1){
    ans^=(idiv=ans>>ish);
    if (idivs=1||ish==32) return ans;}
