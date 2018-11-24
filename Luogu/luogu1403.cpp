#include<cstdio>
using namespace std;

int main()
{
	int n,i,ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		ans+=n/i;
	printf("%d\n",ans);
	return 0;
}
