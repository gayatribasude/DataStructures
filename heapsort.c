#include<stdio.h>
#include<stdlib.h>
/*

TimeComplexity: O(nlogn)
SpaceComplexity: O(1)
inPlace= yes
stable= no

*/
int *a,size,heapsize;
void maxheap(int k){
	int left,right,largest=k,tmp;
	left=k*2+1;
	right=left+1;
	
	if(left<heapsize && a[left]>a[k]){
		largest=left;
	}
	if(right<heapsize && a[largest]<a[right]){
		largest=right;
	}
	if(k!=largest){
		tmp=a[k];
		a[k]=a[largest];
		a[largest]=tmp;
		maxheap(largest);
	}
	

}

void heapSort(){
	int tmp;
	for(int i=size-1;i>=0;i--){
		tmp=a[i];
		a[i]=a[0];
		a[0]=tmp;
		heapsize--;
		maxheap(0);
	}

}

void buidheap(){
	for(int i=size/2;i>=0;i--){
		maxheap(i);
	}
}

void printArray(){
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main(){
	int i;
	printf("enter no. of elements:");
	scanf("%d",&size);
	a=malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printArray();
	heapsize=size;
	buidheap();
	heapSort();
	printf("after sort:");
	printArray();

	return 10;
}