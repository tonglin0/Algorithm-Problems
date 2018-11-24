#include<cstdio>
#include<algorithm>
using namespace std;

int a[100004];

int main()
{
	int n,i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1;i<=n-1;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
