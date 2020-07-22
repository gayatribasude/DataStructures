d=256 # d is the number of characters in the input alphabet 
prime=101

def rka(string,pattern):
	m=len(pattern)#for main string
	n=len(string)#for pattern
	pattern_hash=0
	string_hash=0
	h=1 #h=(d^(m-1))%prime

	for i in range(m-1):
		h=(h*d)%prime
	print("h:",h)

	for i in range(m):
		pattern_hash=(d*pattern_hash+ord(pattern[i]))%prime
		string_hash=(d*string_hash+ord(string[i]))%prime

	for i in range(n-m+1):
		if(pattern_hash==string_hash):
			for j in range(m):
				if(string[j+i]!=pattern[j]):
					break
			if(j+1==m):
				print("found at:",i)
		if(i<n-m):
			string_hash=(d*(string_hash-ord(string[i])*h)+ ord(string[i+m]))%prime
			if(string_hash<0):
				string_hash=string_hash+prime

if __name__ == '__main__':
	pattern=input("add pattern:")
	string=input("add string:")	
	rka(string,pattern)

