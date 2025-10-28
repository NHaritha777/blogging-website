#include<stdio.h>
void BubbleSort(int a[], int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
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
	BubbleSort(a,n);
	printf("\nAfter Sorting elements are : \n");
	for(i=0;i<n;i++)
	printf("%4d",a[i]);
}
