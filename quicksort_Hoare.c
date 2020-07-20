#include<stdio.h>
//#include<stdlib.h>


/*
Hoare's partition 

stable = no
WorseCase = O(n^2) (when array is sorted)

*/
int a[100],n;
int partition(int p,int r){
	int x=a[(p+r)/2],i,j,tmp;
	i=p-1;
	j=r+1;
	while(1){
		do{
			i++;
		}
		while(a[i]<x);
		do{
			j--;
		}
		while(a[j]>x);

		if(i<j){
			tmp=a[j];
			a[j]=a[i];
			a[i]=tmp;
		}
		else{
			return j;
		}
	}

}
void quicksort(int p,int r){
	int q;
	if(p<r){

		q=partition(p,r);
		quicksort(p,q);
		quicksort(q+1,r);

	}
	
}



int main(){
	int i,p,q;
	printf("enter size of the array:");
	scanf("%d",&n);
	printf("enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(0,n-1);

	//print
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}


/*

output:

enter size of the array:9
enter elements:1
2
9
5
7
10
11
12
13
1 2 5 7 9 10 11 12 13

*/