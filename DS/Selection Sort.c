#include<stdio.h>
void SelectionSort(int a[],int n)
{
	int i,t,j,minIndex;
	for(i=0;i<n-1;i++){
		minIndex=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[minIndex])
			    minIndex=j;
		}
		t=a[i];
		a[i]=a[minIndex];
		a[minIndex]=t;
	}
}
void main()
{
	int i,n,j;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	int a[n];
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nBefore Sorting elements are : \n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
	SelectionSort(a,n);
	printf("\nAfter Sorting elements are : \n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
}
