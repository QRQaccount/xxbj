def fun(string, num1, num2):
    if num2 == 10:
        print()
        print("*********")
        print(int(string, num1))
        print("*********")
    elif num2 == 16:
        print()
        print("*********")
        print(hex(int(string, num1)))
        print("*********")
    elif num2 == 2:
        print()
        print("*********")
        print(bin(int(string, num1)))
        print("*********")
    elif num2 == 8:
        print()
        print("*********")
        print(oct(int(string, num1)))
        print("*********")
    else:
        print("i can't read it")


while True:
    string = input()
    l = ["", "", ""]
    k = 0
    if string == "q;":
        break
    for i in string:
        if i != " ":
            l[k] += i
        else:
            k += 1
    fun(l[0], int(l[1]), int(l[2]))
