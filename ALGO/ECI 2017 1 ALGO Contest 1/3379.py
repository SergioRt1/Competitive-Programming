from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def f(i,j):
    if i == j+1: return 0
    if memo[i][j] != -1: return memo[i][j]
    if s[i+1] < s[j]:a = s[i]-s[j]+f(i+1,j-1)
    else: a = s[i]-s[i+1]+f(i+2,j)
    if s[i] < s[j-1]: b = s[j]-s[j-1]+f(i,j-2)
    else: b = s[j]-s[i]+f(i+1,j-1)
    memo[i][j] = max(a,b)
    return memo[i][j]
def main():
    global s
    global memo
    c = 0
    for line in stdin.readlines():
        c += 1
        s = [int(x) for x in line.split()]
        if s == [0]:
            break
        memo = [[-1]*(s[0]+1) for k in range(s[0]+1)]
        stdout.write("In game {}, the greedy strategy might lose by as many as {} points.\n".format(c,f(1,s[0])))
main()
