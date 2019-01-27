from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit(Python) 
#,setrecursionlimit
#setrecursionlimit(1147483647)
#def f(i,j):
 #   if i == M: return 0
  #  if j == N: return 1147483647
   # if L[i] != V[j][0]: return f(i,j+1)
    #memo[i][j] = min(f(i+1,j+1)+V[j][1],f(i,j+1))
    #return memo[i][j]
def itera():
    prue = [[0]*(N+1) for k in range(2)]
    print(prue)
    prue[(M-1)%2][N] = 1147483647
    for i in range(M-1,-1,-1):
        if i == M-2:prue[M%2][N] = 1147483647
        for j in range(N-1,i-1,-1):
            print("valores",i,j)
            if L[i] != V[j][0]: prue[i%2][j] = prue[i%2][j+1]
            else: prue[i%2][j] = min(prue[(i+1)%2][j+1]+V[j][1],prue[i%2][j+1])
    return prue[0][0]
#def itera():
 #   prue = [[0]*(M) for k in range(2)]
  #  for k in range(M): memo[k][N] = 1147483647
   # for i in range(M-1,-1,-1):
    #    for j in range(N-1,i-1,-1):
     #       
      #      if L[i] != V[j][0]: memo[i][j] = memo[i][j+1]
       #     else: memo[i][j] = min(memo[i+1][j+1]+V[j][1],memo[i][j+1])
def main():
    global M,N,L,V,memo
    while True:
        M,N = map(int,stdin.readline().split())
        if 0 == M == N: break
        L = [int(x) for x in stdin.readline().split()]
        V = [(int(k[0]),float(k[1])) for k in (stdin.readline().split() for k in range(N))]
        ans = itera()
        #f(0,0)
        if ans > 1147483620: stdout.write("Impossible\n")
        else: stdout.write("{:.2f}\n".format(ans))
main()
