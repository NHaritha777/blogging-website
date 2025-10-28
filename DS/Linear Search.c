#include<stdio.h>
int LinearSearch(int a[],int n,int s)
{
	int i;
	for(i=0;i<n;i++){
		if(a[i]==s)
		return i;
	}
	return -1;
}
void main()
{
	int n,s,r,i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nEnter the search element: ");
	scanf("%d",&s);
	r= LinearSearch(a,n,s);
	if(r==-1)
	printf("%d is not found in the list",s);
	else
	printf("%d is found at position %d",s,r);
}
