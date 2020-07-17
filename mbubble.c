#include<stdio.h>
#include<stdlib.h>

/*
In best case if data is in ascending order( already sorted)
then no need of checking n or n-1 times,
so function will get break after 1 time of outer loop and n-1 times of inner loop


best case=O(n)
worse case=O(n^2)
space=O(1)
inPlace= yes
stable= yes


*/





int *a,size;
void mbubblesort(){
	int i,j,tmp,flag;
	for(i=0;i<size-1;i++){
		flag=1;
		printf("outer:%d\n",i+1);
		for(j=0;j<size-i-1;j++){
			printf("inner:%d\n",j+1);
			if(a[j]>a[j+1]){
				flag=-1;
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
		if(flag==1){
			break;
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
	mbubblesort();
	printf("after sort:");
	printArray();

	return 10;
}