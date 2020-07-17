#include<stdio.h>
#include<stdlib.h>


/*

worse case=O(n^2)
best case=O(n)
space=O(1)
inPlace= yes
stable= yes

*/


int *a,size;
void insertion(){
	for(int j=1,i;j<size;j++){
		int key=a[j];
		i=j-1;
		while(i>=0 && key<a[i]){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
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
	insertion();
	printf("after sort:");
	printArray();

	return 10;
}