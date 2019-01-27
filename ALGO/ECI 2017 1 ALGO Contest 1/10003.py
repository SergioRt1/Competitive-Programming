from sys import stdin, stdout
#Sergio Andres Rodriguez Torres
#Veredicto: TimeLimit(Python) 
def f(i,j):
    if i+1 == j: return 0
    if memo[i][j] != -1: return memo[i][j]
    memo[i][j] = min(f(i,k)+f(k,j) for k in range(i+1,j))+C[j]-C[i]
    return memo[i][j]
def main():
    global memo
    global C
    while True:
        L = int(stdin.readline())
        if L == 0:
            break
        le = int(stdin.readline())
        memo = [[-1]*(le+2) for k in range(le+2)]
        C = [0]
        C.extend(map(int,stdin.readline().split()))
        C.append(L)
        stdout.write("The minimum cutting is {}.\n".format(f(0,le+1)))
main()
