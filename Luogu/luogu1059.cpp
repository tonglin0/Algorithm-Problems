#include<cstdio>
#include<algorithm>
using namespace std;

int a[1003],b[1003];

int main()
{
	int n,i,top=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++)
		if (i==1||a[i]!=a[i-1])
			b[++top]=a[i];
	printf("%d\n",top);
	for (i=1;i<=top-1;i++)
		printf("%d ",b[i]);
	printf("%d\n",b[top]);
	return 0;
}
