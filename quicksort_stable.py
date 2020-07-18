"""
inPlace = no
stable = yes
TimeComplexity = O(nlogn)
SpaceComplexity =O(n)

"""

def quicksort(l):
	m=len(l)
	if(m==0 or m==1):
		return l
	mid=m//2
	i=0
	small=[]
	large=[]

	while(i<m):
		if(i!=mid):
			if(l[i]>l[mid]):
				large.append(l[i])
			elif(l[i]<l[mid]):
				small.append(l[i])
			else:
				if(i<mid):
					small.append(l[i])
				else:
					large.append(l[i])
		i+=1

	return quicksort(small)+[l[mid]]+quicksort(large)




if __name__=='__main__':
	m=int(input("enter size of list1:"))
	l1=[]
	print("enter %d elements of list:"%(m))
	for _ in range(m):
		l1.append(int(input()))
	l1=quicksort(l1)
	print(l1)




	
	
