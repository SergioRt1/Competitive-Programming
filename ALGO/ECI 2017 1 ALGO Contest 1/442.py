from sys import stdin,stdout
#Sergio Andres Rodriguez Torres
#Veredicto: Accepted
def multi(num2,num1):
    global e
    if num1[2] != num2[1]:
        e = True
    else:
        return num1[0]+num2[0],num1[1],num2[2],num1[1]*num2[1]*num2[2]+num1[3]+num2[3]
def main():
    global e
    n = int(stdin.readline())
    M = {}
    for k in range(n):
        mat = stdin.readline().split()
        M[mat[0]] = (int(mat[1]),int(mat[2]),0)
    lines = stdin.readlines()
    for line in lines:
        par = []
        matr = []
        ans = 0
        e = False
        for c in line.strip():
            if c == "(":
                par.append("(")
            elif c == ")":
                par.pop()
                matr.append(multi(matr.pop(),matr.pop())) 
            else:
                matr.append((c,*M[c]))
            if e:
                print("error")
                break
        else:
            print(matr[0][3])
main()
