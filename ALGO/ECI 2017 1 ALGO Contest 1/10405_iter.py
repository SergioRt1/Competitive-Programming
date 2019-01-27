from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def fl():
    for i in range(A-1,-1,-1):
        for j in range(B-1,-1,-1):
            x = True
            for k in range(j,B):
                if a[i] == b[k]:
                    pos = k
                    break
            else:
                x = False
                memo[i][j] = memo[i+1][j]
            if x: memo[i][j] = max(memo[i+1][pos+1]+1,memo[i+1][j]) 
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
            memo = [[0]*(B+1) for k in range(A+1)]
            v = True
            fl()
            print(memo[0][0])
main()
