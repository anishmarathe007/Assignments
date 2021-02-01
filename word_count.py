with open('abc.txt') as f: s = f.read()

counts = dict()

def word_count(str):
    words = str.split()

    for word in words:
        if word in counts:
            counts[word] += 1
        else:
            counts[word] = 1

    return counts

word_count(s)

word = input("Enter the word whose frequency you want?\n")

if word in counts.keys():
    print(word, "occured" , counts[word], "times")
else:
    print(word, "not found!")
