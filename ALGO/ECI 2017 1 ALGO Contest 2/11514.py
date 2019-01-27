from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted 
def f(i,j):
    if j == V: return 0
    if i == P: return 2047483647
    if memo[i][j] != -1: return memo[i][j]
    if p[i][1] < v[j][1] or p[i][0] not in v[j][2] : return f(i+1,j)
    memo[i][j] = min(f(i+1,j+1)+p[i][2],f(i+1,j))
    return memo[i][j]
def main():
    global memo,p,v,P,V
    while True:
        P,V,E = map(int,stdin.readline().split())
        if(0 == P == V == E): break
        p = [(m[0],int(m[1]),int(m[2])) for m in (stdin.readline().split() for k in range(P))]
        v = [(m[0],int(m[1]),m[2].split(",")) for m in (stdin.readline().split() for k in range(V))]
        memo = [[-1]*V for k in range(P)]
        e = f(0,0)
        if e <= E: stdout.write("Yes\n")
        else: stdout.write("No\n")
main()
