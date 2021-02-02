start = -1
end = -1

while start <= 0 or end <= 0:
	start = int(input("Enter start\n"))
	end = int(input("Enter end\n"))
	#print("Only Positive Integers are allowed!")

while start <= end:
	i=1
	perfectNumber=0
	while i < start:
		if start % i == 0:
			perfectNumber += i
		i += 1
	if perfectNumber == start:
		print(start, end=" ")
	start += 1