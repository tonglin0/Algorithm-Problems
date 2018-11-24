#include<cstdio>
#define lint long long
using namespace std;

lint a[103];

int main()
{
	int n=0,i;
	for (;;)
	{
		scanf("%d",&a[++n]);
		if (a[n]==0)
			break;
	}
	n--;
	printf("%d",a[n]);
	for (i=n-1;i>=1;i--)
		printf(" %d",a[i]);
	printf("\n");
	return 0;
}
