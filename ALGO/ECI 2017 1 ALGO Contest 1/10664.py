from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def f(i,c):
    if i == d: return False
    if c > mid: return False
    if c == mid: return True
    if c in memo[i]: return memo[i][c]
    memo[i][c] = max(f(i+1,c+ob[i]),f(i+1,c))
    return memo[i][c]

def main():
    global ob, mid, d,memo
    for k in range(int(stdin.readline())):
        ob = [int(x) for x in stdin.readline().split()]
        d = len(ob)
        s = sum(ob)
        if s/2 != s>>1:stdout.write("NO\n")
        else:
            memo = [{} for k in range(d)]
            mid = s>>1
            if f(0,0): stdout.write("YES\n")
            else: stdout.write("NO\n")
main()
