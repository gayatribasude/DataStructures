"""
To store two no. on same index we use this formula
ai= ai + new_value * max_ele

old_value = ai % max_ele
new_value = ai // max_ele

TimeComplexity = O(max(m,n))
SpaceComplexity = O(1)

"""

def mergesort(l1,l2):
	m=len(l1)
	n=len(l2)
	max_element=1+max(l1[m-1],l2[n-1])
	i=0
	k=0
	j=0
	while(i<m and j<n):
		left=l1[i]%max_element
		right=l2[j]%max_element
		if(left<right):
			
			if(k<m):
				l1[k]=l1[k]+left*max_element
			else:
				l2[k-m]=l2[k-m]+left*max_element
			i+=1
		else:
			if(k<m):
				l1[k]=l1[k]+right*max_element
			else:
				l2[k-m]=l2[k-m]+right*max_element
			j+=1
		k+=1


	while(i<m):
		left=l1[i]%max_element
		if(k<m):
			l1[k]=l1[k]+left*max_element
		else:
			l2[k-m]=l2[k-m]+left*max_element
		i+=1
		k+=1
	while(j<n):
		right=l2[j]%max_element
		if(k<m):
			l1[k]=l1[k]+right*max_element
		else:
			l2[k-m]=l2[k-m]+right*max_element
		j+=1
		k+=1


	print()
	print()
	for i in l1:
		print(i//max_element,end=" ")
	print()
	for i in l2:
		print(i//max_element,end=" ")
	print()


if __name__=='__main__':
	m=int(input("enter size of list1:"))
	n=int(input("enter size of list2:"))
	l1=[]
	l2=[]
	print("enter %d sorted elements of list1:"%(m))
	for _ in range(m):
		l1.append(int(input()))
	print("enter %d sorted elements of list2:"%(n))	
	for _ in range(n):
		l2.append(int(input()))

	mergesort(l1,l2)

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

	
	
