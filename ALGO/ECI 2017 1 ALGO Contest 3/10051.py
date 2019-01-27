from sys import stdin,stdout,setrecursionlimit
setrecursionlimit(9999999)
#Sergio Andres Rodriguez Torres
#Veredicto: Runtime error
def f(i,j):
    if i == N: return 0
    print(i,j)
    if memo[i][j] != -1: return memo[i][j]
    ad = [la for la in range(6) if cubs[i+1][la] == j]
    if ad:
        tom = max(f(i+1,cubs[i+1][k^1]) for k in ad)+1
        memo[i][j] = max(f(i+1,j),tom)
    else:
        memo[i][j] = f(i+1,j)
    return memo[i][j]
def main():
    global memo, N,cubs
    while True:
        n = int(stdin.readline())
        if not n: break
        cubs = [[int(x) for x in stdin.readline().split()] for k in range(n)]
        memo = [[-1]*(n+1) for k in range(n+1)]
        N = n-1
        print(max((f(0,cubs[0][k])) for k in range(6))+1)
main()
