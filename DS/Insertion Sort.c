#include<stdio.h>
void InsertionSort(int a[],int n)
{
	int i,k,j;
	for(i=1;i<n;i++){
		k=a[i];
		j=i-1;
		while(j>=0 && a[j]>k){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
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
	InsertionSort(a,n);
	printf("\nAfter Sorting elements are : \n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
}
