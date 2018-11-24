#include<cstdio>
using namespace std;

int main()
{
	int n,x,i,ans=0;
	scanf("%d%d",&n,&x);
	for (i=1;i<=n;i++)
	{
		int t=i;
		while(t)
		{
			if (t%10==x)
				ans++;
			t/=10;
		}
	}
	printf("%d\n",ans);
	return 0;
}
