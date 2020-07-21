"""
m:length of pattern
n: length of main string

Space = O(m) for table of pattern(longest preffix suffix table)
Time = O(m)+O(n) (O(m) for table creation, O(n) for main traversal)
"""



def table(pattern,t):
	i=0
	j=1
	while(j<len(pattern)):
		if(pattern[i]!=pattern[j]):
			i=0
		else:	
			i+=1
		t[j]=i
		j+=1



def kmp(string,pattern):
	t=[0]*len(pattern)
	table(pattern,t)
	j=0 #for main string
	i=0 #for pattern
	flag=0
	print(t)
	while(j<len(string)):
		if(string[j]!=pattern[i]):
			i=t[i]
			
			if(string[j]==pattern[i]):
				j+=1
				i+=1
			else:
				j+=1
		else:
			j+=1
			i+=1
		if(i==len(pattern)):
			flag=1
			print("true true true,found at:%d"%(j-len(pattern)))
			i=t[i-1]
	if(flag==0):
		print("not found")


# pattern='dsgwadsgz'
# string='adsgwadsxdsgwadsgz'

# pattern='gay'
# string='gaygaytrigayatri'

# pattern="anananananil"
# string ="ananananananananananananil"

# pattern="aaba"
# string="aabaacaadaabaaba"
pattern=input("add pattern:")
string=input("add string:")
kmp(string,pattern)


