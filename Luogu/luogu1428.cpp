#include<cstdio>
using namespace std;

int a[204];

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("0");
	for (i=2;i<=n;i++)
	{
		int s=0;
		for (int j=1;j<i;j++)
			if (a[j]<a[i])
				s++;
		printf(" %d",s);
	}
	printf("\n");
	return 0;
}
