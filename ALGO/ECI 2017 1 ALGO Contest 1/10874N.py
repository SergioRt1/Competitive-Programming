from sys import stdin,stdout,setrecursionlimit
setrecursionlimit(999999)
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def f(niv,act):
    if niv == n: return n - sec[niv][0] + abs(sec[niv][0] - act)
    if act in memo[niv]: return memo[niv][act]
    memo[niv][act] = min(f(niv+1,sec[niv][0]) + abs(act - sec[niv][1]),f(niv+1,sec[niv][1]) + abs(act - sec[niv][0])) + sec[niv][1] - sec[niv][0] 
    return memo[niv][act]
def main():
    global memo, n,sec,N
    while True:
        n = int(stdin.readline())
        if not n: break
        memo = [{} for k in range(n+1)]
        sec = {k:[int(x) for x in stdin.readline().split()] for k in range(1,n+1)}
        print(f(1,1)+n-1)
main()
    
