#include<stdio.h>
#include<stdlib.h>
/*

Divide and Conquer

best case=O(nlogn)
worse case=O(nlogn)
avg case=O(nlogn)

therefore time complexity: theta(nlogn)

space=O(logn)+O(n) (stack and array)
therefore space complexity: O(n)

inPlace= no
stable= yes


*/
int *a;
void merge(int start,int mid,int last){
	int tmp[100],i=start,j=mid+1,k=0;
	while(i<=mid && j<=last){
		if(a[i]>a[j]){
			tmp[k++]=a[j++];
		}
		else{
			tmp[k++]=a[i++];
		}
	}
	while(i<=mid){
		tmp[k++]=a[i++];
	}

	while(j<=last){
		tmp[k++]=a[j++];
	}

	j=0;
	for(i=start;i<=last;i++){
		a[i]=tmp[j++];
	}

}

void mergeSort(int start,int last){
	if(start<last){
		int p=(start+last)/2;
		mergeSort(start,p);
		mergeSort(p+1,last);
		merge(start,p,last);
		
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
	mergeSort(0,n-1);
	printf("after sort:");
	printArray(n);

	return 10;
}