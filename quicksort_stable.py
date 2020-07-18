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


"""		
APPLEs-MacBook-Air:ExamTime newmac$ python3 merge_sort_without_space.py
enter size of list1:3
enter size of list2:5
enter 3 elements of list1:
2
4
5
enter 5 elements of list2:
1
3
5
7
9


1 2 3 
4 5 5 7 9 

"""

	
	
