#include<stdio.h>
#include<stdlib.h>


/*
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.


*) advantage over bubble: less swaps only O(n) swaps

avg case=O(n^2)
space=O(1)
inPlace= yes
stable= yes

*/

int *a,size;
void selection(){
	int i,j,tmp,small;
	for(i=0;i<size;i++){
		small=i;
		for(j=i+1;j<size;j++){
			if(a[small]>a[j]){
				small=j;
			}
		}
		tmp=a[small];
		a[small]=a[i];
		a[i]=tmp;
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
	selection();
	printf("after sort:");
	printArray();

	return 10;
}