#include<stdio.h>
#include<stdlib.h>

/*
In worse case if data is in descending order
then swapping will be (n-1) for first time
then next time (n-2)
then (n-3)
.... 1 swap at the end
therefor 
T(n)=(n-1)+(n-2)+(n-3)+....1
T(n)=(n(n-1))/2


worse case=O(n^2)
space=O(1)
inPlace= yes
stable= yes
*/





int *a,size;
void bubblesort(){
	int i,j,tmp;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
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
	bubblesort();
	printf("after sort:");
	printArray();

	return 10;
}