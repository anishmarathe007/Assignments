data = {}

def insertIntoBook(name,author):
	if name not in data.keys():
		data[name] = author
		print("Book Successfully Inserted!")
	else:
		print("Book with the same name already exists!")

def search(name):
	if name in data.keys():
		print(name, "Present. Author name is : ", data[name])
	else:
		print(name,"not present in the shelf.")

def deleteBook(name):
	if name in data.keys():
		print(name, "Deleted!")
		data.pop(name)
	else:
		print(name, "Not Present")

def displayBooks():
	print("Book Name\tAuthor Name")
	for key in data.keys():
		print(key,"\t",data[key])

while True:
	print("1.Enter New Book\n2.Search for a book\n3.Delete a book\n4.Display a book\n5.Exit")
	ch = int(input("Enter the choice.\n"))

	if ch==1:
		name = input("Enter the name of the book.\n")
		author = input("Enter the name of author for book\n")
		insertIntoBook(name,author)

	elif ch==2:
		name = input("Enter the name of the book you want to search!\n")
		search(name)

	elif ch==3:
		name = input("Enter the name of the book you want to delete!\n")
		deleteBook(name)

	elif ch==4:
		displayBooks()

	elif ch==5:
		exit(0)

	else:
		print("Wrong Choice!")