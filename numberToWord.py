def numberToWord(n, suffix):

    if n == 0:
        return NOTHING

    if n > 19:
        return Y[n // 10] + X[n % 10] + suffix
    else:
        return X[n] + suffix

def convert(n):
    if n == 0 :
        return "Zero"

    result = numberToWord(( n // 10000000000000000000) % 100, "Maha Shankh ")

    result += numberToWord(( n // 100000000000000000) % 100, "Shankh ")

    result += numberToWord(( n // 1000000000000000) % 100, "Padma ")

    result += numberToWord(( n // 10000000000000) % 100, "Neel ")

    result += numberToWord(( n // 100000000000) % 100, "Kharab ")

    result += numberToWord((n // 1000000000) % 100, "Arab ")

    result += numberToWord((n // 10000000) % 100, "Crore ")

    result += numberToWord(((n // 100000) % 100), "Lakh ")

    result += numberToWord(((n // 1000) % 100), "Thousand ")

    result += numberToWord(((n // 100) % 10), "Hundred ")

    result += numberToWord((n % 100), "")

    return result


#this is where the execution starts..!!
if __name__ == '__main__':

    print("Hello and Welcome. I am a Number to Word Converter.")

    NOTHING = ""

    X = [NOTHING, "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
         "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
         "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ",
         "Seventeen ", "Eighteen ", "Nineteen "]

    Y = [NOTHING, NOTHING, "Twenty ", "Thirty ", "Forty ", "Fifty ",
         "Sixty ", "Seventy ", "Eighty ", "Ninety "]

    ui = 'yes'

    while ui != 'no' :
        try :
            inputNum = input("Enter the Number which you want to convert to Words\n");
            ip = int(inputNum)
            if len(inputNum) > 21 :
                print("Exceeded the limit for processing. Please enter it again.")
            elif(ip<0) :
                print("Entered number is negative. But I can still process that number\n")
                ip = (-ip)
                print('Minus ' + convert(ip))
                print("Do you want to convert some more numbers? (Enter yes : to continue or no : to exit)")
                ui = input()
            else:
                print(convert(ip))
                print("Do you want to convert some more numbers? (Enter yes : to continue or no : to exit)")
                ui = input()
        except(ValueError):
            print("You have entered alphabet(s) or Invalid String or Floats, Whereas I can process only Integer numbers\n")
