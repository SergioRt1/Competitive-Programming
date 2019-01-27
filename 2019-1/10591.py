from sys import stdin,stdout
def desc(n):
    n = int(n)
    return n*n
    
def main():
    cas = int(stdin.readline().strip())+1
    for cc in range(1,cas):
        n = stdin.readline().strip();
        if not n:break
        ini = int(n)
        happy = True
        for k in range(60):
            n = str(n)
            n = sum(desc(i) for i in n)
            if n == 4:
                happy = False
                break
            if n == 1:break
        stdout.write("Case #{}: {} is a".format(cc,ini))
        if happy: stdout.write(" Happy number.\n")
        else: stdout.write("n Unhappy number.\n")
main()
