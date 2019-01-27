from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Time limit exceeded
def phi():
    m = len(s)
    p = [0]*m
    k = 0
    for q in range(1,m):
        while k > 0 and s[k] != s[q]:
            k = p[k-1]
        if s[k] == s[q]: k += 1
        p[q] = k
    return p
def main():
    global s,p,s
    cas = 0
    while True:
        cas += 1
        if not int(stdin.readline()):break
        s = stdin.readline().strip()
        stdout.write("Test case #{}\n".format(cas))
        p = phi()
        for i in range(2,len(s)+1):
            if p[i-1] and not i%(i-p[i-1]):
                print(i,i//(i-p[i-1]))
        stdout.write("\n")
main()
        
