from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def f(i,j):
    if i == A: return 0
    if j == B: return 0
    if memo[i][j] != 0: return memo[i][j]
    x = True
    for k in range(j,B):
        if a[i] == b[k]:
            pos = k
            break
    else:
        x = False
        memo[i][j] = f(i+1,j)
    if x: memo[i][j] = max(f(i+1,pos+1)+1,f(i+1,j))
    return memo[i][j]
def main():
    global a, b, A, B, memo 
    v = True
    for line in stdin.readlines():
        if v:
            a = line.strip()
            A = len(a)
            v = False
        else:
            b = line.strip()
            B = len(b)
            memo = [[0]*B for k in range(A)]
            v = True
            print(f(0,0))
main()
