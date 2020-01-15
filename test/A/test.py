key = input().strip()
a, b = map(int, input().split())

# print(key)
for i in range (1, len(key)):
	left = key[:i]
	right = key[i:]
	if(left[0]=='0') :
		continue
	if(right[0]=='0'):
		continue
	if int(left)%a == 0 and int(right)%b == 0 :
		print("YES")
		print(left)
		print(right)
		exit(0)

print("NO")	
