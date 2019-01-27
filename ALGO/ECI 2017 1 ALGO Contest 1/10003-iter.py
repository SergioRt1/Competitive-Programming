from sys import stdin, stdout
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit(Python) 
def fl():
    for diag in range(2,n+2):
        i = 0
        for j in range(diag,n+2):
            memo[i][j] = min(memo[i][k] + memo[k][j] for k in range(i+1,j))+C[j]-C[i]
            i += 1
def main():
    global memo
    global C
    global n
    while True:
        L = int(stdin.readline())
        if L == 0:
            break
        n = int(stdin.readline())
        memo = [[0]*(n+2) for k in range(n+2)]
        C = [0]
        C.extend(map(int,stdin.readline().split()))
        C.append(L)
        fl()
        stdout.write("The minimum cutting is {}.\n".format(memo[0][n+1]))
main()
