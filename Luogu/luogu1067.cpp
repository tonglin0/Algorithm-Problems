#include<cstdio>
#include<cstring>
using namespace std;

int a[100003];

int main()
{
	int n,i,k;
	scanf("%d",&n);
	for (i=n;i>=0;i--)
		scanf("%d",&a[i]);
	for (i=n;i>=2;i--)
	{
		if (a[i]==0) continue;
		if (i!=n&&a[i]>0) printf("+");
		if (a[i]!=1&&a[i]!=-1)
			printf("%dx^%d",a[i],i);
		if (a[i]==1)
			printf("x^%d",i);
		else if (a[i]==-1)
			printf("-x^%d",i);
	}
	if (n>=1&&a[1]!=0)
	{
		if (a[1]>0) printf("+");
		if (a[1]!=1&&a[1]!=-1)
			printf("%dx",a[1]);
		else if (a[1]==1)
			printf("x");
		else if (a[1]==-1)
			printf("-x");
	}
	if (a[0]!=0)
	{
		if (a[0]>0) printf("+");
		printf("%d",a[0]);
	}
	printf("\n");
	return 0;
}
