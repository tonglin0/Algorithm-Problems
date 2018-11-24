#include<cstdio>
#include<ctime>
#include<algorithm> 
#include<cstring>
using namespace std;

int ans=0;
int a[12];

void work(int p,int n)
{
	if (p==11)
	{
		if (n==0) ans++;
		return ;
	}
	for (int i=1;i<=min(n,3);i++)
		work(p+1,n-i);
}

void work2(int p,int n)
{
	if (p==11)
	{
		if (n==0)
		{
			for (int i=1;i<=9;i++)
				printf("%d ",a[i]);
			printf("%d\n",a[10]);
		}
		return ;
	}
	for (int i=1;i<=min(n,3);i++)
	{
		a[p]=i;
		work2(p+1,n-i);
	}
}

int main()
{
	freopen("2089.in","r",stdin);
	freopen("2089.out","w",stdout);
	int n,i;
	scanf("%d",&n);
	work(1,n);
	printf("%d\n",ans);
	work2(1,n);
	//printf("%.6lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
