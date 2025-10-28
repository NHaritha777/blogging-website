#include<stdio.h>
int BinarySearch(int a[],int n, int s)
{
	int l=0,h=n-1;
	int i;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==s) return mid;
		else if(a[mid]<s) l=mid+1;
		else h=mid-1;
	}
	return -1;
}
void main()
{
	int i,s,r,n;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter elemnts: \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the search element: ");
	scanf("%d",&s);
	r= BinarySearch(a,n,s);
	if(r==-1) printf("%d is not found in the array",s);
	else printf("%d is found at %d position ",s,r);
}
