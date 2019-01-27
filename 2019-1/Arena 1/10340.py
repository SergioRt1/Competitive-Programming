from sys import stdin,stdout
def main():
    while True:
        ln = stdin.readline()
        if not ln:break
        s,t = ln.strip().split()
        i = 0
        le = len(s)
        ans = False
        for k in t:
            if i >= le:
                ans = True
                break
            if k == s[i]: i+=1
        if i >= le:
            ans = True
        if ans: stdout.write("Yes\n")
        else: stdout.write("No\n")
main()
