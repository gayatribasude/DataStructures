#include<stdio.h>
#include<stdlib.h>

/*

Divide and Conquer

best case=theta(nlogn)
worse case=O(n^2)
avg case=O(nlogn)

therefore time complexity: theta(nlogn)
space=O(n)
inPlace= yes
stable= no


*/

int *a;
int partition(int start,int last){
	int i,j,pivot,tmp;
	pivot=last,i=start-1,j=start;
	for(;j<last;j++){
		if(a[j]<a[pivot]){
			tmp=a[j];
			a[j]=a[++i];
			a[i]=tmp;
		}
	}
	tmp=a[pivot];
	a[pivot]=a[i+1];
	a[i+1]=tmp;

	return i+1;
}

void quicksort(int start,int last){
	if(start<last){
		int p=partition(start,last);
		quicksort(start,p-1);
		quicksort(p+1,last);
	}

}
void printArray(int size){
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int i,n;
	printf("enter no. of elements:");
	scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printArray(n);
	quicksort(0,n-1);
	printf("after sort:");
	printArray(n);

	return 10;
}