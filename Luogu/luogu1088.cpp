#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[10003];

int main()
{
	int n,i,m;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (i=1;i<=m;i++)
		next_permutation(a+1,a+n+1);
	for (i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
