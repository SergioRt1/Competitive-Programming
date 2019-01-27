from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def fd():
    for diag in range(3,s[0]+1,2):
        i = 0
        for j in range(diag,s[0]+1):
            if s[i+1] < s[j]:a = s[i]-s[j]+memo[i+1][j-1]
            else: a = s[i]-s[i+1]+memo[i+2][j]
            if s[i] < s[j-1]: b = s[j]-s[j-1]+memo[i][j-2]
            else: b = s[j]-s[i]+memo[i+1][j-1]
            memo[i][j] = max(a,b)
            i += 1
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
        i = 0 
        for j in range(1,s[0]+1):
            memo[i][j] = abs(s[i]-s[j])
            i += 1
        fd()
        stdout.write("In game {}, the greedy strategy might lose by as many as {} points.\n".format(c,memo[1][s[0]]))
main()
