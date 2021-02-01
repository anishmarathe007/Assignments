inputS = input("Enter the string\n")

def reverseString(s):
    str = ''
    for i in s:
        str = i + str
    return str

rev = reverseString(inputS)

if inputS == rev:
    print(inputS , "is Palindrome")
else:
    print(inputS , "is not a Palindrome")

