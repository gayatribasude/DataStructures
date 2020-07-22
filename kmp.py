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
			while(i>=0 and pattern[i]!=pattern[j]):
				i=i-1
			if(pattern[i]==pattern[j]):
				i+=1
			else:
				i=0
		else:	
			i+=1
		print(i)
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
			i=t[i-1]
			if(string[j]==pattern[i]):
				i+=1
		else:
			i+=1
		j+=1
		if(i==len(pattern)):
			flag=1
			print("true true true,found at:%d"%(j-len(pattern)))
			i=t[i-1]
	if(flag==0):
		print("not found")


# pattern='dsgwadsgz'
# string='adsgwadsxdsgwadsgz'
# [0, 0, 0, 0, 0, 1, 2, 3, 0]
# true true true,found at:9

# pattern='gay'
# string='gaygaytrigayatri'
# [0, 0, 0]
# true true true,found at:0
# true true true,found at:3

# pattern="anananananil"
# string ="ananananananananananananil"
# [0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 0]
# true true true,found at:14


# pattern="aaba"
# string="aabaacaadaabaaba"
# [0, 1, 0, 1]
# true true true,found at:0
# true true true,found at:9
# true true true,found at:12

pattern=input("add pattern:")
string=input("add string:")
kmp(string,pattern)


